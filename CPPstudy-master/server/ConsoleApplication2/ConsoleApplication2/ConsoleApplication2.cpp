// 서버

#include"class.hpp"

//#include<boost/ref.hpp>
//#include<boost/thread.hpp>

//using namespace std;
//using namespace boost::asio;

const char SERVER_ip[] = "127.0.0.1";
constexpr std::size_t PORT_NUMBER = 31400;
constexpr std::size_t MAX = 100;

/*
2. 멀티 쓰레딩 지원 소켓처리? -> 클라이언트 포트넘버 지정하는 방법 생각, 닫힌 소켓 다시 열 방법 생각 V
+ 비동기화
3. DB연동 lite sql
4. mutex 알아보기
5. window form사용
*/
/* 소켓 쓰레드
https://github.com/jacking75/boost_asio_sample/blob/master/Document/asio_thread_model.md
https://stackoverflow.com/questions/24112662/calling-boostasioio-servicerun-from-a-stdthread
https://www.slideshare.net/jacking/kgc-2012boostasio
*/

void socket_threading(CarManager* CarManager, std::size_t i);//CarManager* CarManager,  ,CarManager* &CarManager , , boost::asio::io_service& _io_service

int main()
{
	CarManager* carManager = CarManager::getInstance("CarListFile.txt"); //

	std::cout << "접속 대기중" << std::endl;
	int number = 1;
	std::thread t[MAX];
	for (std::size_t i = 0; i < MAX; ++i)
	{
		t[i] = std::thread(socket_threading, carManager, i);//, boost::ref(io_service[i])
	}
	for (std::size_t i = 0; i < MAX; ++i)
	{
		t[i].join();
	}
	return 0;
}

void socket_threading(CarManager* CarManager, std::size_t i)//, boost::asio::ip::tcp::socket socket CarManager* &CarManager, , boost::asio::io_service & _io_service
{
	{
		std::unique_ptr<boost::asio::io_service> _io_service = std::make_unique< boost::asio::io_service>();
		boost::asio::ip::tcp::endpoint	endpoint(boost::asio::ip::tcp::v4(), static_cast<unsigned short>(PORT_NUMBER + i));
		boost::asio::ip::tcp::acceptor acceptor(*_io_service, endpoint);
		boost::asio::ip::tcp::socket socket(*_io_service);
		acceptor.accept(socket);//접속대기

		std::cout << "user" << i << "  연결" << "PORT_NUMBER : " << PORT_NUMBER + i << std::endl;
		for (;;)
		{
			char number = 0;
			boost::system::error_code error;

			socket.read_some(boost::asio::buffer(&number, 1), error);//읽기 대기

			if (error)
			{
				if (error == boost::asio::error::eof)
					std::cout << "연결 끊김" << std::endl;
				else
					std::cout << "error no." << error.value() << ", error message:" << error.message() << std::endl;
				break;
			}
			CarManager->set(number - '0', i, socket);
		}
		std::cout << "user" << i << "  연결끊김 " << std::endl;
	}
	socket_threading(CarManager, i); // 다시 포트를 연다.
}