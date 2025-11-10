#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <iostream> 
using namespace std;

class OrderBook {
private:
    map<double, int> buyOrders;  // price -> quantity
    mutex mtx;
    // NO MUTEX!
    
public:
    void addBuyOrder(double price, int quantity) {
        lock_guard<mutex> lock(mtx);
        // BUG: No lock! Race on map access!
        if (buyOrders.find(price) != buyOrders.end()) {
            buyOrders[price] += quantity;
        } else {
            buyOrders[price] = quantity;
        }
    }
    
    int getTotalQuantity() {
        lock_guard<mutex> lock(mtx);
        int total = 0;
        for (auto& [price, qty] : buyOrders) {
            total += qty;
        }
        return total;
    }
};

void addOrders(OrderBook& book, int numOrders) {
    for (int i = 0; i < numOrders; i++) {
        book.addBuyOrder(2500.0, 100);
    }
}

int main() {
    OrderBook book;
    
    vector<thread> threads;
    for (int i = 0; i < 5; i++) {
        threads.emplace_back(addOrders, ref(book), 1000);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    cout << "Total quantity: " << book.getTotalQuantity() << endl;
    // Expected: 500,000
    // Actual: Less, or CRASH!
    
    return 0;
}