#include <iostream>
#include <chrono>
#include "ThreadPool.h"

using namespace std;

void func2(int i)
{
	std::cout << "task" << i << " working in thread:" << std::this_thread::get_id() << std::endl;
}

int main(int argc, char** argv)
{
	ThreadPool pool(3);
	pool.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	for(int i = 0; i != 6; ++i)
	{
		pool.append(std::bind(func2, i));
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	pool.stop();
	getchar();
	return 0;
}
