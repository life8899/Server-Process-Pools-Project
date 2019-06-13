#pragma once
#ifndef CLIENT_H
#define CLIENT_H


#include "../HttpMessage/HttpMessage.h"
#include "../Sockets/Sockets.h"
#include "../FileSystem/FileSystem.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"
#include <string>
#include <iostream>
#include <thread>
#include "../Sockets/Sockets.h"
using namespace Sockets;

class MsgClient
{
public:

	void ClientSender();
	bool connectSocketStatus(std::string addr, int portNo, SocketConnecter& si);
	void ClientReceiver();
	MsgClient(std::string taddr = "localhost:8080", std::string tpath = "ClientRepository\\")
	{
		addr = taddr.substr(0, taddr.find(':'));
		port = std::stoi(taddr.substr(taddr.find(':') + 1, taddr.size()));
		path = tpath;
	}
	void HandleCommonFunction(std::string msg);
	void HandleCheckIn(std::string msg, std::string cmd);
	void StartClientSenRec();
private:
	std::string addr;
	BlockingQueue<HttpMessageFunc>& sendQueue = StaticBlockingQueue<HttpMessageFunc, 4>().getQueue();	//store the static sending blocking queue
	int port;
	std::string path;
};
#endif