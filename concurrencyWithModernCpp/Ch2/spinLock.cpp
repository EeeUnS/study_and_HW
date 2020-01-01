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
	std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
	void unlock();
};

Spinlock::Spinlock()  //c2280 error
{
	;
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
	////공유 리소스
	spin.unlock();
}



int main()
{
	
	std::thread t(workOnResource);
	std::thread t2(workOnResource);

	t.join();
	t2.join();
}