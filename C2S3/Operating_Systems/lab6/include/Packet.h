#ifndef PACKET_H
#define PACKET_H

enum Action { BALANCE = 1, PUT, WITHDRAW, TRANSFER, QUIT };

typedef struct Packet
{
	unsigned int id, clientID, targetClientID, action;
	unsigned short bankID;

	double money;

} Packet;

#endif
