#include <iostream>
#include <vector>
using namespace std;

class OrderManager {
public:
    vector<string> orderIds = {"ORD001", "ORD002", "ORD003", "ORD004", "ORD005"};
    
    void cancelOrdersContaining(const string& substring) {
        cout << "Cancelling orders containing: " << substring << endl;
        
        for (auto it = orderIds.begin(); it != orderIds.end(); ++it) {
            if (it->find(substring) != string::npos) {
                cout << "Cancelling: " << *it << endl;
                orderIds.erase(it);  // BUG! Invalidates iterator!
                // ++it in loop uses invalid iterator!
            }
        }
    }
    
    void displayOrders() {
        cout << "Remaining orders: ";
        for (const auto& id : orderIds) {
            cout << id << " ";
        }
        cout << endl;
    }
};

int main() {
    OrderManager manager;
    
    cout << "Initial orders:" << endl;
    manager.displayOrders();
    
    // Try to cancel orders containing "ORD00"
    manager.cancelOrdersContaining("ORD00");
    
    cout << "\nAfter cancellation:" << endl;
    manager.displayOrders();
    
    return 0;
}