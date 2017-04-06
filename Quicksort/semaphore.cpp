#include "semaphore.h"

void Semaphore::wait()
{
	std::unique_lock<std::mutex> lock(mutex);
	while (!numThreadsInside)
	{
		cv.wait(lock);
	}

	--numThreadsInside;

	return;
}

void Semaphore::signal()
{
	std::unique_lock<std::mutex> lock(mutex);
	++numThreadsInside;
	lock.unlock();
	cv.notify_all();
	return;
}