#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
using namespace std;

class OrderCounter {
public:
    atomic<int> count = 0;  // Shared variable - NO PROTECTION!
    
    void incrementCount() {
        count++;  // BUG: Not atomic! Race condition!
    }
    
    int getCount() {
        return count;
    }
};

void processOrders(OrderCounter& counter, int ordersToProcess) {
    for (int i = 0; i < ordersToProcess; i++) {
        counter.incrementCount();
    }
}

int main() {
    OrderCounter counter;
    
    const int THREADS = 10;
    const int ORDERS_PER_THREAD = 1000;
    
    vector<thread> threads;
    
    // Start 10 threads, each incrementing 1000 times
    for (int i = 0; i < THREADS; i++) {
        threads.emplace_back(processOrders, ref(counter), ORDERS_PER_THREAD);
    }
    
    // Wait for all threads
    for (auto& t : threads) {
        t.join();
    }
    
    cout << "Expected count: " << (THREADS * ORDERS_PER_THREAD) << endl;
    cout << "Actual count: " << counter.getCount() << endl;
    
    // Expected: 10,000
    // Actual: Random number < 10,000 (race condition!)
    
    return 0;
}

