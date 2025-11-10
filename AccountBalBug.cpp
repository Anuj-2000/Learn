#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class TradingAccount {
public:
    double balance = 100000.0;  // ₹1 lakh initial balance
    
    bool placeOrder(double orderValue) {
        // Check if sufficient balance
        if (balance >= orderValue) {  // BUG: Race condition!
            // Simulate some processing time
            this_thread::sleep_for(chrono::microseconds(10));
            
            // Deduct amount
            balance -= orderValue;
            return true;
        }
        return false;
    }
    
    double getBalance() {
        return balance;
    }
};

void placeMultipleOrders(TradingAccount& account, int numOrders) {
    for (int i = 0; i < numOrders; i++) {
        if (account.placeOrder(10000.0)) {  // Each order ₹10k
            cout << "Order placed by thread " << this_thread::get_id() << endl;
        }
    }
}

int main() {
    TradingAccount account;
    
    cout << "Initial balance: " << account.getBalance() << endl;
    
    vector<thread> threads;
    
    // 3 threads, each trying to place 5 orders
    for (int i = 0; i < 3; i++) {
        threads.emplace_back(placeMultipleOrders, ref(account), 5);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    cout << "Final balance: " << account.getBalance() << endl;
    
    // Initial: 100,000
    // Each order: 10,000
    // Max orders possible: 10
    // Expected final balance: 0 or positive
    // Actual: NEGATIVE! (Race condition!)
    
    return 0;
}