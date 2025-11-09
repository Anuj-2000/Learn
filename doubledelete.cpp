#include <iostream>
#include<memory>
using namespace std;

class Order {
public:
    string id;
    Order(string i) : id(i) {
        cout << "Order " << id << " created" << endl;
    }
    ~Order() {
        cout << "Order " << id << " deleted" << endl;
    }
};

void processOrder(Order* order) {
    cout << "Processing order..." << endl;
    delete order;  // Delete here
}

int main() {
    Order* order = new Order("ORD001");
    //unique_ptr<Order> order = make_unique<Order>("ORD001");

    processOrder(order);
    
    delete order;  // BUG: Double delete! Already deleted in processOrder!
    
    return 0;
}