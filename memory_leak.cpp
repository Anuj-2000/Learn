#include <iostream>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <memory>
using namespace std;

class Order {
public:
    string symbol;
    int quantity;
    double price;
    
    Order(string s, int q, double p) 
        : symbol(s), quantity(q), price(p) {
        cout << "Order created: " << symbol << endl;
    }
    
    ~Order() {
        cout << "Order deleted: " << symbol << endl;
    }
};

class OrderManager {
public:
    void processOrder(string symbol, int qty, double price) {
        //Order* order = new Order(symbol, qty, price);

        auto order = make_unique<Order>(symbol, qty, price);
        
        // Validate
        if (qty <= 0) {
            cout << "Invalid order!" << endl;
         
            return;  // BUG: Forgot to delete order!
        }
        
        // Process
        cout << "Processing order..." << endl;
        
        
        // BUG: Forgot to delete order here too!
    }
    
    void processBatch() {
        for (int i = 0; i < 5; i++) {
            processOrder("RELIANCE", 100, 2500.00);
        }
        // BUG: 5 orders leaked!
    }
};

int main() {
    OrderManager manager;
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    cout << "=== Processing Valid Orders ===" << endl;
    manager.processBatch();
    
    cout << "\n=== Processing Invalid Order ===" << endl;
    manager.processOrder("TCS", -10, 3000.00);  // Invalid
    
    cout << "\n=== Program Ending ===" << endl;

    return 0;
}