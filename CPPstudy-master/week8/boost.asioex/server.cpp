// 서버

#include <iostream>
#include<boost/asio.hpp>

using namespace std;
using namespace boost::asio;

const char SERVER_IP[] = "127.0.0.1";
const unsigned short PORT_NUMBER = 31400;

int main()
{
	io_service io_service;
	ip::tcp::endpoint	endpoint(ip::tcp::v4(), PORT_NUMBER);
	ip::tcp::acceptor	acceptor(io_service, endpoint);
	ip::tcp::socket		socket(io_service);

	acceptor.accept(socket);

	cout << "클라이언트 연결" << endl;

	for (;;)
	{
		char buf[128] = { 0 };
		boost::system::error_code error;
		socket.read_some(buffer(buf), error);//읽기 대기

		if (error)
		{
			if (error == error::eof)
				cout << "연결 끊김" << endl;
			else
				cout << "error No." << error.value() << ", error message:" << error.message() << endl;
			break;
		}
		cout << "클라이언트로부터 : " << buf << endl;

		char r_buf[128] = { 0 };
		boost::system::error_code r_error;

		sprintf_s(r_buf, 128 - 1, "RE : %s", buf);
		int len_r_buf = strnlen_s(r_buf, 128 - 1);

		socket.write_some(buffer(r_buf, len_r_buf), r_error);
		cout << "보낸 메시지 : " << r_buf << endl;
	}
	system("pause");
	return 0;
}
