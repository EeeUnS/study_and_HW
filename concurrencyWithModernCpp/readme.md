

```c++

#include<thread>

std::this_thread::sleep_for(std::chrono::milliseconds(/*time*/));

#include<mutex>

std::mutex mut
mut.lock();
mut.unlock();
std::lock_guard<std::mutex>  //RAII

std::scoped_lock
std::unique_lock


```