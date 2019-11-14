//client
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include"RSA.h"
#include<stdlib.h>
//using namespace std;
//using namespace boost::asio;

const char SERVER_IP[] = "127.0.0.1";
constexpr unsigned short PORT_NUMBER = 31400;

int main()
{
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(SERVER_IP), PORT_NUMBER);
	boost::asio::ip::tcp::socket socket(io_service);
	boost::system::error_code c_error;

	// connect
	socket.connect(endpoint, c_error);
	RSA rsa;
	if (c_error)
	{
		if (c_error == boost::asio::error::eof)
			std::cout << "연결 끊김" << std::endl;
		else
			std::cout << "error No." << c_error.value() << ", error message" << c_error.message() << std::endl;
		getchar();
		return 0;
	}
	// =======
	std::cout << "서버 연결 성공" << std::endl;


	boost::system::error_code error;
	char buffer[80];
	//public key line = (e,n)
	socket.read_some(boost::asio::buffer(buffer, 80), error);

	int e = 0, n = 0;
	std::cout << buffer << std::endl;

	//get integer
	int i = 0;
	while (buffer[i] != ',')
	{
		if ((buffer[i] >= '0' && buffer[i] <= '9'))
		{
			e *= 10;
			e += buffer[i] - '0';
		}
		i++;
	}
	while (buffer[i] != ')')
	{
		if ((buffer[i] >= '0' && buffer[i] <= '9'))
		{
			n *= 10;
			n += buffer[i] - '0';
		}
		i++;
	}
	/////////////////////////////
	memset(buffer, 0, 80);
	rsa.setter_public_key(std::make_pair(e, n));
	for (;;)
	{
		std::cout << "<<";
		std::cin >> buffer;
		rsa.Encryption(buffer);
		if (buffer == "-1")
		{
			break;
		}
		socket.write_some(boost::asio::buffer(buffer,80), error);
		if (error)
		{
			if (error == boost::asio::error::eof)
				std::cout << "연결 끊김" << std::endl;
			else
				std::cout << "error no." << error.value() << ", error message:" << error.message() << std::endl;
			break;
		}
		memset(buffer, 0, 80);
	}
	socket.close();
	std::cout << "클라이언트 종료" << std::endl;
	return 0;
}
//socket.write_some(boost::asio::buffer(&input, 1), error);

//
////클라
//
//#include <iostream>
//
//#include <boost/asio.hpp>
//
//
//
//using namespace std;
//
//using namespace boost::asio;
//
//
//
//const char SERVER_IP[] = "127.0.0.1";
//
//const unsigned short PORT_NUMBER = 31400;
//
//
//
//int main()
//
//{
//
//	io_service io_service;
//
//	ip::tcp::endpoint endpoint(ip::address::from_string(SERVER_IP), PORT_NUMBER);
//
//	ip::tcp::socket	  socket(io_service);
//
//	boost::system::error_code c_error;
//
//
//
//	// connect
//
//	socket.connect(endpoint, c_error);
//
//	if (c_error)
//
//	{
//
//		if (c_error == error::eof)
//
//			cout << "연결 끊김" << endl;
//
//		else
//
//			cout << "error No." << c_error.value() << ", error message" << c_error.message() << endl;
//
//		getchar();
//
//		return 0;
//
//	}
//
//	// =======
//
//	cout << "서버 연결 성공" << endl;
//
//	for (int i = 0; i < 7; i++)
//
//	{
//
//		char buf[128] = { 0 };
//
//		sprintf_s(buf, 128 - 1, "%d 보냄", i);
//
//		int len_buf = strnlen_s(buf, 128 - 1);
//
//		boost::system::error_code error;
//
//		socket.write_some(buffer(buf, len_buf), error);
//
//		cout << "보낸 메시지 : " << buf << endl;
//
//
//
//		char r_buf[128] = { 0 };
//
//		boost::system::error_code r_error;
//
//		socket.read_some(buffer(r_buf), r_error);
//
//		if (r_error)
//
//		{
//
//			if (r_error == error::eof)
//
//				cout << "연결 끊김" << endl;
//
//			else
//
//				cout << "error No." << r_error.value() << ", error message" << r_error.message() << endl;
//
//			break;
//
//		}
//
//		cout << "서버로부터 : " << r_buf << endl;
//
//	}
//
//	if (socket.is_open())
//
//	{
//
//		socket.close();
//
//	}
//
//	cout << "클라이언트 종료" << endl;
//
//
//
//	return 0;
//
//}
//
