﻿#include <SDKDDKVer.h>


#include "ChattingServer.h"



const int MAX_SESSION_COUNT = 100;

int main()
{
	boost::asio::io_context io_service;

	ChatServer server(io_service);
	server.Init(MAX_SESSION_COUNT);
	server.Start();

	io_service.run();


	std::cout << "연결 종료" << std::endl;

	getchar();
	return 0;
}