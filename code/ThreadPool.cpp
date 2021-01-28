#include "ThreadPool.h"
#include <iostream>

ThreadPool::ThreadPool(int count)
	: threadCount_(count)
	  , isRunning_(false)
{
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::start()
{
	isRunning_ = true;
	for(int i = 0; i != threadCount_; ++i)
		threads_.emplace_back(std::thread(&ThreadPool::work, this));
}

void ThreadPool::work()
{
	std::cout << "begin work thread:" << std::this_thread::get_id() << std::endl;
	while(isRunning_)
	{
		Task task;
		std::unique_lock<std::mutex> lock(mutex_);
		if (!tasks_.empty())
		{
			task = tasks_.front();
			tasks_.pop();
		}
		else if(isRunning_ && tasks_.empty())
			condition_.wait(lock);
		if (task)
			task();
	}
	std::cout << "end work thread:" << std::this_thread::get_id() << std::endl;
}	
