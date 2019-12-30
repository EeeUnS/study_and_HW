//spinLock.cpp


#include <atomic>
#include <thread>


class Spinlock
{
public:
	Spinlock();
	~Spinlock();
	void lock();
private:
	std::atomic_flag flag;
public:
	void unlock();
};

Spinlock::Spinlock(): flag(ATOMIC_FLAG_INIT)
{
}

Spinlock::~Spinlock()
{
}
void Spinlock::lock()
{
	while (flag.test_and_set());
}

void Spinlock::unlock()
{
	flag.clear();
}

Spinlock spin;

void workOnResource()
{
	spin.lock();
	//공유 리소스
	spin.unlock();
}
