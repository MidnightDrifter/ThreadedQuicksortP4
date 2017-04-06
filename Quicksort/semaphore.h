#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
class Semaphore
{
public:



	Semaphore(int m) : numThreadsInside(m),  cv(),  mutex() {}

	int getNumThreadsInside() const { return numThreadsInside; }


	void wait();
	void signal();
private:

	
	int numThreadsInside;
	std::condition_variable cv;
	std::mutex mutex;
};
