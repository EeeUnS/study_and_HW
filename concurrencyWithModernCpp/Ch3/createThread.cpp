//createThread.cpp

#include <iostream>
#include <thread>

void helloFunction()
{
	std::cout << "Hello from a fuction." << std::endl;
}

class HelloFuctionOject
{
public:
	HelloFuctionOject();
	~HelloFuctionOject();
	void operator()() const
	{
		std::cout << "Hello from a fuction object." << std::endl;
	}
private:

};

HelloFuctionOject::HelloFuctionOject()
{
}

HelloFuctionOject::~HelloFuctionOject()
{
}

int main()
{
	std::cout << std::endl;

	std::thread t1(helloFunction);

	HelloFuctionOject helloFunctionObject;
	std::thread t2(helloFunctionObject);

	std::thread t3([] 
		{std::cout << "Hello from a lambda." << std::endl; }
	);

	t1.join();
	t2.join();
	t3.join();

	std::cout << std::endl;

}