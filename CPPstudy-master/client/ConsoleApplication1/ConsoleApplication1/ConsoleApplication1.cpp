
#include <iostream>
#include <string>
#include <boost/asio.hpp>

//using namespace std;
//using namespace boost::asio;

const char SERVER_IP[] = "127.0.0.1";
//constexpr unsigned short PORT_NUMBER = 31411;

int main()
{
	int PORT_NUMBER = 31400;
	while (1)
	{
		std::cout << "포트 번호를 눌러주세요 31400~ 31499" << std::endl;
		std::cin >> PORT_NUMBER;
		if (31400 <= PORT_NUMBER && PORT_NUMBER <= 31499)
			break;
	}

	boost::asio::io_service io_service;
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(SERVER_IP), PORT_NUMBER);
	boost::asio::ip::tcp::socket socket(io_service);
	boost::system::error_code c_error;
	// connect
	socket.connect(endpoint, c_error);
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
	for (;;)
	{
		boost::system::error_code error;
		char input;
		char number;
		std::cout << "Car Manager Menu" << std::endl;
		std::cout << "1. Print Car List" << std::endl;
		std::cout << "2. Find Car Info" << std::endl;
		std::cout << "3. exit" << std::endl;
		std::cout << "Input number : ";
		char line[80] = { 0 };
		std::cin >> input;
		std::string brand, model;
		switch (input - '0')
		{
		case 1:
			std::cout << std::endl;
			socket.write_some(boost::asio::buffer(&input, 1), error);
			socket.read_some(boost::asio::buffer(&number, 1), error);
			for (int i = 0; i < number; i++)
			{
				socket.read_some(boost::asio::buffer(line, 80), error);
				std::cout << line << std::endl;
				memset(line, 0, 80);
			}
			break;
		case 2:
			std::cout << "Brand : ";
			std::cin >> brand;
			std::cout << "Model : ";
			std::cin >> model;
			std::cout << std::endl;
			socket.write_some(boost::asio::buffer(&input, 1), error);
			Sleep(1);
			socket.write_some(boost::asio::buffer(brand, brand.length()), error);
			Sleep(1);
			socket.write_some(boost::asio::buffer(model, model.length()), error);
			socket.read_some(boost::asio::buffer(line, 80), error);
			std::cout << line << std::endl;
			break;
		case 3:
			socket.write_some(boost::asio::buffer(&input, 1), error);
			socket.close();
			goto END;
		default:
			std::cout << "Input Val Error" << std::endl;
			break;
		}
	}
END:
	std::cout << "클라이언트 종료" << std::endl;
	return 0;
}