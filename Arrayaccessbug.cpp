#include <iostream>
#include <vector>
using namespace std;

class OrderProcessor {
public:
    void processOrders(vector<int> orderIds) {
        cout << "Processing " << orderIds.size() << " orders" << endl;
        
        for (int i = 0; i <= orderIds.size(); i++) {  // BUG: <=
            cout << "Order ID: " << orderIds[i] << endl;
        }
    }
};

int main() {
    vector<int> orders = {101, 102, 103, 104, 105};
    
    OrderProcessor processor;
    processor.processOrders(orders);
    
    return 0;
}