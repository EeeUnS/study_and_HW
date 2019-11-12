// ¼­¹ö

#include"class.hpp"
#include<thread>

using namespace std;
using namespace boost::asio;

const char SERVER_IP[] = "127.0.0.1";
unsigned short PORT_NUMBER = 31400;


//void socket_threading( CarManager &carManager, ip::tcp::socket socket);

int main()
{
	CarManager *carManager = CarManager::getInstance("CarListFile.txt");
	int i = 0;
	io_service io_service;
	ip::tcp::endpoint	endpoint(ip::tcp::v4(), PORT_NUMBER);
	/*ip::tcp::acceptor	acceptor(io_service, endpoint);
	ip::tcp::socket		socket(io_service);*/
	
	int number = 1;
	//thread i[100];

	while (1) {
		cout << "Á¢¼Ó ´ë±âÁß" << endl;
		ip::tcp::acceptor	acceptor(io_service, endpoint);
		ip::tcp::socket		socket(io_service); 
		acceptor.accept(socket);//Á¢¼Ó´ë±â
		cout << "user" << ++i << "  ¿¬°á" << endl;
		for (;;)
		{
			char number = 0;
			boost::system::error_code error;

			socket.read_some(buffer(&number, 1), error);//ÀÐ±â ´ë±â
			Sleep(1);
			if (error)
			{
				if (error == error::eof)
					cout << "¿¬°á ²÷±è" << endl;
				else
					cout << "error No." << error.value() << ", error message:" << error.message() << endl;
				break;
			}

			carManager->set(number - '0', i, socket);

		}
		cout << "user" << i << "  ¿¬°á²÷±è " << endl;

	}
	
	system("pause");
	return 0;


}

/*	i[number] = thread(socket_threading , socket, carManager);
		i[number].join();*/


//
//void socket_threading( CarManager &carManager, )
//{
//	cout << "user" << i << "  ¿¬°á" << endl;
//	for (;;)
//	{
//		char number = 0;
//		boost::system::error_code error;
//
//		socket.read_some(buffer(&number, 1), error);//ÀÐ±â ´ë±â
//
//		if (error)
//		{
//			if (error == error::eof)
//				cout << "¿¬°á ²÷±è" << endl;
//			else
//				cout << "error No." << error.value() << ", error message:" << error.message() << endl;
//			break;
//		}
//
//		carManager.set(number - '0', i - '0', socket);
//
//	}
//	cout << "user" << i << "  ¿¬°á²÷±è " << endl;
//
//}