#include <shared_mutex>
#include <mutex>
#include <iostream>
#include <thread>
#include <vector>

class ThreadSafeCounter {
private:
    mutable std::shared_mutex mutex_;  // mutable for const functions
    int value_ = 0;

public:
    // READ operation - multiple threads allowed
    int get() const {
        std::shared_lock lock(mutex_);  // Shared (read) lock
        return value_;
    }

    // WRITE operation - exclusive access
    void increment() {
        std::unique_lock lock(mutex_);  // Unique (writ8*e) lock
        value_++;
    }

    void set(int val) {
        std::unique_lock lock(mutex_);
        value_ = val;
    }
};

int main() {
    ThreadSafeCounter counter;

    // Spawn 10 reader threads
    std::vector<std::thread> readers;
    for(int i = 0; i < 10; i++) {
        readers.emplace_back([&counter]() {
            for(int j = 0; j < 1000; j++) {
                int val = counter.get();  // Multiple can read together!
            }
        });
    }

    // Spawn 2 writer threads
    std::vector<std::thread> writers;
    for(int i = 0; i < 2; i++) {
        writers.emplace_back([&counter]() {
            for(int j = 0; j < 1000; j++) {
                counter.increment();  // Exclusive access
            }
        });
    }

    // Wait for all threads
    for(auto& t : readers) t.join();
    for(auto& t : writers) t.join();

    std::cout << "Final value: " << counter.get() << std::endl;

    return 0;
}
