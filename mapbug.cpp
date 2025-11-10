#include <map>
#include <iostream>
using namespace std;

class OrderTracker {
public:
    map<string, int> orderCount;
    
    void addOrder(const string& symbol) {
        orderCount[symbol]++;
    }
    
    int getOrderCount(const string& symbol) {
        return orderCount[symbol];  // BUG! Creates entry if not exists!
    }
    
    bool hasOrders(const string& symbol) {
        return orderCount[symbol] > 0;  // BUG! Always creates entry!
    }
    
    void displayStats() {
        cout << "Total symbols tracked: " << orderCount.size() << endl;
        for (const auto& [symbol, count] : orderCount) {
            cout << "  " << symbol << ": " << count << endl;
        }
    }
};

int main() {
    OrderTracker tracker;
    
    // Add some orders
    tracker.addOrder("RELIANCE");
    tracker.addOrder("RELIANCE");
    tracker.addOrder("TCS");
    
    cout << "After adding orders:" << endl;
    tracker.displayStats();
    
    // Check if INFY has orders (it doesn't!)
    cout << "\nChecking INFY..." << endl;
    if (tracker.hasOrders("INFY")) {
        cout << "INFY has orders" << endl;
    } else {
        cout << "INFY has no orders" << endl;
    }
    
    cout << "\nAfter checking INFY:" << endl;
    tracker.displayStats();  // BUG! INFY was added!
    
    // Get count for WIPRO (doesn't exist)
    cout << "\nGetting WIPRO count..." << endl;
    int count = tracker.getOrderCount("WIPRO");
    cout << "WIPRO count: " << count << endl;
    
    cout << "\nAfter getting WIPRO count:" << endl;
    tracker.displayStats();  // BUG! WIPRO was added too!
    
    return 0;
}