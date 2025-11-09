#include <iostream>
#include <vector>
using namespace std;

class Order {
public:
    string id;
    int quantity;
    
    Order(string i, int q) : id(i), quantity(q) {}
    
    void display() {
        cout << "Order: " << id << ", Qty: " << quantity << endl;
    }
};

int main() {
    Order* order = new Order("ORD001", 100);
    
    order->display();  // OK
    
    delete order;      // Deleted here
    
    cout << "Order deleted" << endl;
    
    order->display();  // BUG! Use after free!
    
    return 0;
}