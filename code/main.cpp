#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char** argv)
{
	cout << std::thread::hardware_concurrency() << endl;
	return 0;
}
