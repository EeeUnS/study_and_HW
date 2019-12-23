
//ex 3-1 synchronousTCPServer
#include <iostream>
#include <boost/asio.hpp>
//using namespace std;
//using namespace boost::asio;

const char SERVER_IP[] = "127.0.0.1";
const unsigned short PORT_NUMBER = 31400;

int main()
{
	//클라이언트 접속 준비 핵심
	boost::asio::io_service io_service;
	//네트워크 주소 설정
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), PORT_NUMBER);
	//클라이언트 접속 받기
	boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
	boost::asio::ip::tcp::socket socket(io_service);
	acceptor.accept(socket);

	std::cout << "클라이언트 접속" << std::endl;
		 
	for (;;)
	{
		std::array<char, 128> buf = { 0, };

		//error code wrapping class
		boost::system::error_code error;
		std::size_t len = socket.read_some(boost::asio::buffer(buf), error);

		if (error)
		{
			if (error == boost::asio::error::eof)
			{
				std::cout << "클라이언트와 연결이 끊어졌습니다." << std::endl;
			}
			else
			{
				std::cout << " error No:" << error.value() << "error Message: " << error.message() << std::endl;
			}
			break;
		}

		std::cout << "클라이언트에서 받은 메세지" << &buf[0] << std::endl;
		
		char szMessage[128] = { 0, };
		sprintf_s(szMessage, 128 - 1, "Re:%s", &buf[0]);
		std::size_t nMsgLen = strnlen_s(szMessage, 128 - 1);

		boost::system::error_code ignored_error;
		socket.write_some(boost::asio::buffer(szMessage, nMsgLen), ignored_error);
		std::cout << "클라이언트에 보낸 메시지: " << szMessage << std::endl;
	}
	getchar();
	return 0;
}