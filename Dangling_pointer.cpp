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

class OrderBook {
public:
    vector<Order*> orders;
    
    void addOrder(Order* order) {
        orders.push_back(order);
    }
    
    void removeOrder(int index) {
        if (index < orders.size()) {
            delete orders[index];  // Delete the order
            orders.erase(orders.begin() + index);  // Remove from vector
        }
    }
    
    void displayOrders() {
        cout << "=== All Orders ===" << endl;
        for (Order* order : orders) {
            order->display();  // BUG: Might be deleted!
        }
    }
};

int main() {
    OrderBook book;
    
    // Add orders
    book.addOrder(new Order("ORD001", 100));
    book.addOrder(new Order("ORD002", 200));
    book.addOrder(new Order("ORD003", 300));
    
    cout << "Before removal:" << endl;
    book.displayOrders();  // Works fine
    
    // Remove middle order
    book.removeOrder(1);
    
    cout << "\nAfter removal:" << endl;
    book.displayOrders();  // Still works (removed from vector)
    
    // But what if someone kept a pointer?
    Order* dangling = book.orders[0];
    book.removeOrder(0);  // Deletes the order
    
    dangling->display();  // BUG! Use after free!
    
    return 0;
}