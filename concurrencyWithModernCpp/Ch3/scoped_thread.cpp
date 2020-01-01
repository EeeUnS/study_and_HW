//scoped_thread.cpp


#include <iostream>
#include <thread>
#include <utility>


class scoped_thread
{
public:
	explicit scoped_thread(std::thread t_);
	~scoped_thread();
	scoped_thread(scoped_thread&) = delete;
	scoped_thread& operator=(scoped_thread const&) = delete;
private:
	std::thread t;
};

explicit scoped_thread::scoped_thread(std::thread t_) : t(std::move(t_))
{
	if (!t.joinable())
		throw std::logic_error("No thread");
}

scoped_thread::~scoped_thread()
{
	t.join();
}