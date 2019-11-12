//클라

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

const char SERVER_IP[] = "127.0.0.1";
const unsigned short PORT_NUMBER = 31400;

int main()
{

	io_service io_service;
	ip::tcp::endpoint endpoint(ip::address::from_string(SERVER_IP), PORT_NUMBER);
	ip::tcp::socket	  socket(io_service);
	boost::system::error_code c_error;
	// connect
	socket.connect(endpoint, c_error);
	if (c_error)
	{
		if (c_error == error::eof)
			cout << "연결 끊김" << endl;
		else
			cout << "error No." << c_error.value() << ", error message" << c_error.message() << endl;
		getchar();
		return 0;
	}
	// =======
	cout << "서버 연결 성공" << endl;
	for (;;)
	{
		boost::system::error_code error;
		char input;
		char number;
		cout << "Car Manager Menu" << endl;
		cout << "1. Print Car List" << endl;
		cout << "2. Find Car Info" << endl;
		cout << "3. exit" << endl;
		cout << "Input number : ";
		char line[80] = { 0 };
		cin >> input;
		string brand, model;
		switch (input-'0')
		{
		case 1:
			cout << endl;
			socket.write_some(buffer(&input, 1), error);
			socket.read_some(buffer(&number, 1), error);
			for (int i = 0; i < number; i++)
			{
				socket.read_some(buffer(line, 80), error);
				cout << line << endl;
				memset(line, 0, 80);
			}
			break;
		case 2:
			cout << "Brand : ";
			cin >> brand;
			cout << "Model : ";
			cin >> model;
			cout << endl;
			socket.write_some(buffer(&input, 1), error);
			Sleep(1);
			socket.write_some(buffer(brand, brand.length()), error);
			Sleep(1);
			socket.write_some(buffer(model, model.length()), error);
			socket.read_some(buffer(line, 80), error);
			cout << line << endl;
			break;
		case 3:
			socket.close();
			goto END;
		default:
			cout << "Input Val Error" << endl;
			break;
		}
	}
END:
	cout << "클라이언트 종료" << endl;
	system("pause");
	return 0;
}
