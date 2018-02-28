/*
 * Created by darkloned.
 * Task 3:
 *  Create ZeroMQ banking environment.
 *
 * See log files for usage example.
 */

#include <iostream>
#include <cstring>
#include <unistd.h>

#include "zmq.h"

#include "Bank.h"
#include "Packet.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./Server [port]" << std::endl;

		return 1;
	}

	unsigned short serverPort = atoi(argv[1]); // TCP uses 2^16 pool [0..65535]
	char serverAddress[32] = {'\0'};
	Bank* bankServer = new Bank(serverPort);

	sprintf(serverAddress, "%s%hu", "tcp://*:", serverPort);

	void* context = zmq_ctx_new();
	void* socket = zmq_socket(context, ZMQ_REP);

	zmq_bind(socket, serverAddress);

	std::cout << "Bank server started." << std::endl << std::endl;

	for (;;) 
	{
		zmq_msg_t request;

		zmq_msg_init(&request);
		zmq_msg_recv(&request, socket, 0);

		Packet* requestData = (Packet*) zmq_msg_data(&request);

		std::cout << "Packet #" << requestData->id << ": client ID " << requestData->clientID << "." << std::endl;

		zmq_msg_close(&request);

		bankServer->newAccount(requestData->clientID);

		zmq_msg_t zmqReply;
		char reply[128];

		switch (requestData->action)
		{
			case BALANCE:
				sprintf(reply, "Balance: %.2lf credits.", bankServer->getBalanceOf(requestData->clientID));
				std::cout << "Balance status sent." << std::endl;

				break;

			case PUT:
			{
				bankServer->putMoneyTo(requestData->targetClientID, requestData->money);

				sprintf(reply, "Done.");
				std::cout << "Put " << requestData->money << " credits to client ID " << requestData->targetClientID << "." << std::endl;

				break;
			}
			case WITHDRAW:
				std::cout << "Withdraw " << requestData->money << " credits... ";

				if (bankServer->withdrawMoneyFrom(requestData->clientID, requestData->money))
				{
					sprintf(reply, "Done.");
					std::cout << "OK." << std::endl;
				} 
				else
				{
					sprintf(reply, "Rejected. Low balance.");
					std::cout << "Rejected." << std::endl;
				}

				break;

			case TRANSFER:
			{
				std::cout << "Transfer " << requestData->money << " credits to " << requestData->targetClientID << "@" << requestData->bankID << "... ";

				if (bankServer->withdrawMoneyFrom(requestData->clientID, requestData->money))
				{
					sprintf(reply, "Done.");
					std::cout << "OK." << std::endl;

					if (requestData->bankID == serverPort)
					{
						bankServer->putMoneyTo(requestData->targetClientID, requestData->money);
						std::cout << "Put " << requestData->money << " credits to client ID " << requestData->targetClientID << "." << std::endl;
						sprintf(reply, "Done.");
						
					}
					else
					{
						void* transferSocket = zmq_socket(context, ZMQ_REQ);

						char transferAddress[32] = {'\0'};
						sprintf(transferAddress, "%s%hu", "tcp://localhost:", requestData->bankID);
						zmq_connect(transferSocket, transferAddress);

						zmq_msg_t transferRequest;
						Packet transferRequestData = *requestData;

						transferRequestData.action = PUT;

						zmq_msg_init_size(&transferRequest, sizeof(Packet));

						memcpy(zmq_msg_data(&transferRequest), &transferRequestData, sizeof(Packet));

						zmq_msg_send(&transferRequest, transferSocket, 0);
						zmq_msg_close(&transferRequest);

						zmq_msg_t zmqTransferReply;
						zmq_msg_init(&zmqTransferReply);
						zmq_msg_recv(&zmqTransferReply, transferSocket, 0);

						char* transferReply = (char*) zmq_msg_data(&zmqTransferReply);

						zmq_msg_close(&zmqTransferReply);

						zmq_close(transferSocket);

						sprintf(reply, "Reply from target bank: %s", transferReply);
					}
				} 
				else
				{
					sprintf(reply, "Rejected. Low balance.");
					std::cout << "Rejected." << std::endl;
				}

				break;
			}

			default:
				sprintf(reply, "Unknown request. Please try again.");
				std::cout << "Unknown request." << std::endl;
		}

		std::cout << std::endl;

		zmq_msg_init_size(&zmqReply, strlen(reply) + 1);

		memcpy(zmq_msg_data(&zmqReply), reply, strlen(reply) + 1);

		zmq_msg_send(&zmqReply, socket, 0);
		zmq_msg_close(&zmqReply);
	}

	zmq_close(socket);
	zmq_ctx_destroy(context);

	return 0;
}
