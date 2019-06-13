#pragma once
#ifndef SERVER_H
#define SERVER_H

#include "../HttpMessage/HttpMessage.h"
#include "../Sockets/Sockets.h"
#include "../FileSystem/FileSystem.h"
#include "../Logger/Cpp11-BlockingQueue.h"
#include "../Logger/Logger.h"
#include "../Utilities/Utilities.h"

#include <string>
#include <iostream>
class Server
{
public:

	void ServerSender();
	void ServerReceiver();
	bool connectSocketStatus(std::string addr, int portNo, SocketConnecter& si);
	Server(std::string taddr = "localhost:8081", std::string tpath = "ServerRepository\\")
	{
		addr = taddr.substr(0, taddr.find(':'));
		port = std::stoi(taddr.substr(taddr.find(':') + 1, taddr.size()));
		path = tpath;
		FileSystem::Directory::setCurrentDirectory(path);
	}

private:
	std::string addr;
	BlockingQueue<HttpMessageFunc>& sendQueue = StaticBlockingQueue<HttpMessageFunc, 4>().getQueue();
	int port;
	std::string path;
};
#endif 




