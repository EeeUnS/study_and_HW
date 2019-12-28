﻿#include <SDKDDKVer.h>

#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

class BackGroundJobManager
{
	boost::asio::io_context& m_io_service;
	boost::shared_ptr<boost::asio::io_context::work> m_Work;
	boost::thread_group m_Group;

public:
	BackGroundJobManager(boost::asio::io_context& io_service, std::size_t size)
		: m_io_service(io_service)
	{
		m_Work.reset(new boost::asio::io_context::work(m_io_service));

		for (std::size_t i = 0; i < size; ++i)
		{
			m_Group.create_thread(boost::bind(&boost::asio::io_context::run, &m_io_service));
		}
	}

	~BackGroundJobManager()
	{
		m_Work.reset();
		m_Group.join_all();
	}

	template <class F>
	void post(F f)
	{
		boost::asio::post(f);
	}
};


void Function(int nNumber)
{
	char szMessage[128] = { 0, };
	sprintf_s(szMessage, 128 - 1, "%s(%d) | time(%I64d)", __FUNCTION__, nNumber, time(NULL));
	{
		std::cout << "worker thread ID: " << ::GetCurrentThreadId() << ". " << szMessage << std::endl;
	}

	::Sleep(1000);
}

int main()
{
	std::cout << "main thread ID: " << ::GetCurrentThreadId() << std::endl;

	boost::asio::io_context io_service;
	BackGroundJobManager JobManager(io_service, 3);

	boost::asio::io_context::strand st(io_service);
	JobManager.post(boost::asio::bind_executor(st, boost::bind(Function, 11)));
	JobManager.post(boost::asio::bind_executor(st, boost::bind(Function, 12)));

	::Sleep(3000);
	return 0;
}
