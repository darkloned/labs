/*
 * Created by darkloned.
 * Task 3:
 *  Create ZeroMQ banking environment.
 *
 * See log files for usage example.
 */

#include <iostream>
#include <limits>
#include <unistd.h>
#include <cstring>
#include <cmath>

#include "zmq.h"

#include "Packet.h"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage: ./Client [ID] [server port]" << std::endl;

		return 1;
	}

	unsigned int clientID = atoi(argv[1]);
	unsigned short serverPort = atoi(argv[2]); // TCP uses 2^16 pool [0..65535]
	char serverAddress[32] = {'\0'};

	sprintf(serverAddress, "%s%hu", "tcp://localhost:", serverPort);

	void* context = zmq_ctx_new();
	void* socket = zmq_socket(context, ZMQ_REQ);

	zmq_connect(socket, serverAddress);

	std::cout << "Bank client started." << std::endl << std::endl;

	std::cout << "Available requests:" << std::endl;
	std::cout << "1) Balance" << std::endl;
	std::cout << "2) Put" << std::endl;
	std::cout << "3) Withdraw" << std::endl;
	std::cout << "4) Transfer" << std::endl;
	std::cout << "5) Quit" << std::endl << std::endl;

	int packetID = 1;

	for (;;) 
	{
		zmq_msg_t request;
		Packet requestData;

		requestData.id = packetID;
		requestData.clientID = clientID;
		requestData.targetClientID = clientID;

		std::cout << "Request ID: ";
		std::cin >> requestData.action;

		if (std::cin.fail()) 
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

     		std::cout << "Unknown request. Please try again." << std::endl << std::endl;

     		continue;
 		}

		switch (requestData.action) 
		{
			case PUT:
				std::cout << "Amount of credits to put: ";
				std::cin >> requestData.money;
				requestData.money = round(requestData.money * 100.) / 100.;

				break;

			case WITHDRAW:
				std::cout << "Amount of credits to withdraw: ";
				std::cin >> requestData.money;
				requestData.money = round(requestData.money * 100.) / 100.;

				break;

			case TRANSFER:
				std::cout << "Amount of credits to transfer: ";
				std::cin >> requestData.money;
				std::cout << "Target bank: ";
				std::cin >> requestData.bankID;
				std::cout << "Target client: ";
				std::cin >> requestData.targetClientID;

				break;

			case QUIT:
				std::cout << "Quit." << std::endl;

				return 0;
		}

		zmq_msg_init_size(&request, sizeof(Packet));

		memcpy(zmq_msg_data(&request), &requestData, sizeof(Packet));

		zmq_msg_send(&request, socket, 0);
		zmq_msg_close(&request);

		zmq_msg_t reply;

		zmq_msg_init(&reply);
		zmq_msg_recv(&reply, socket, 0);

		std::cout << (char*) zmq_msg_data(&reply) << std::endl << std::endl;

		zmq_msg_close(&reply);

		packetID++;
	}

	zmq_close(socket);
	zmq_ctx_destroy(context);

	return 0;
}
