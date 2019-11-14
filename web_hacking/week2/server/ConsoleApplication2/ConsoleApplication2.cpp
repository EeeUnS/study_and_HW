//// 서버

#include"RSA.h"
#include<iostream>
#include<boost/asio.hpp>
#include<string>

//using namespace std;
//using namespace boost::asio;

const char SERVER_ip[] = "127.0.0.1";
constexpr std::size_t PORT_NUMBER = 31400;

//https://heurinbada.tistory.com/105

int main()
{
	std::cout << "접속 대기중" << std::endl;
	int number = 1;
	std::unique_ptr<boost::asio::io_service> _io_service = std::make_unique< boost::asio::io_service>();
	boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::tcp::v4(), static_cast<unsigned short>(PORT_NUMBER));
	boost::asio::ip::tcp::acceptor acceptor(*_io_service, endpoint);
	boost::asio::ip::tcp::socket socket(*_io_service);

	acceptor.accept(socket);//접속대기
	std::cout << "연결" << "PORT_NUMBER : " << PORT_NUMBER  << std::endl;

	RSA rsa;
	rsa.generate_key(17, 7);
	auto key = rsa.getter_public_key();

	std::string line = '(' + std::to_string(key.first) + ',' + std::to_string(key.second) + ')';
	boost::system::error_code error;
	socket.write_some(boost::asio::buffer(line, line.length()), error);

	for (;;)
	{
		char read_line[80] = {0,};
		socket.read_some(boost::asio::buffer(read_line,80), error);//읽기 대기

		if (error)
		{
			if (error == boost::asio::error::eof)
				std::cout << "연결 끊김" << std::endl;
			else
				std::cout << "error no." << error.value() << ", error message:" << error.message() << std::endl;
			break;
		}
		std::cout << "Encrypt >> "<< read_line << '\n';
		rsa.Decryption(read_line);
		std::cout << ">> " << read_line << '\n';

	}
	std::cout << "  연결끊김 " << std::endl;




	return 0;
}
//
//#include <iostream>
//
//#include <boost/asio.hpp>
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
//{
//	io_service io_service;
//	ip::tcp::endpoint	endpoint(ip::tcp::v4(), PORT_NUMBER);
//	ip::tcp::acceptor	acceptor(io_service, endpoint);
//	ip::tcp::socket		socket(io_service);
//	acceptor.accept(socket);
//
//	cout << "클라이언트 연결" << endl;
//
//	for (;;)
//	{
//		char buf[128] = { 0 };
//		boost::system::error_code error;
//		socket.read_some(buffer(buf), error);
//
//		if (error)
//		{
//
//			if (error == error::eof)
//
//				cout << "연결 끊김" << endl;
//
//			else
//
//				cout << "error No." << error.value() << ", error message:" << error.message() << endl;
//
//			break;
//
//		}
//
//		cout << "클라이언트로부터 : " << buf << endl;
//
//
//
//		char r_buf[128] = { 0 };
//
//		boost::system::error_code r_error;
//
//
//
//		sprintf_s(r_buf, 128 - 1, "RE : %s", buf);
//
//		int len_r_buf = strnlen_s(r_buf, 128 - 1);
//
//
//
//		socket.write_some(buffer(r_buf, len_r_buf), r_error);
//
//		cout << "보낸 메시지 : " << r_buf << endl;
//
//	}
//
//
//
//	return 0;
//
//}



