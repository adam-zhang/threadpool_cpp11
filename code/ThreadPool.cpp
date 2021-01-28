#include "ThreadPool.h"

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
	
}
