#include <condition_variable>

std::queue<int> dataQueue;
std::mutex mtx;
std::condition_variable cv;

// Producer thread
void producer() {
    for (int i = 0; i < 10; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            dataQueue.push(i);
        }
        cv.notify_one();  // "Hey consumer, data is ready!"
    }
}

// Consumer thread — waits efficiently (no busy-looping)
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !dataQueue.empty(); });
        // ↑ Sleeps until queue is non-empty. Releases lock while sleeping.

        int val = dataQueue.front();
        dataQueue.pop();
        lock.unlock();

        std::cout << "Got: " << val << std::endl;
    }
}
