#include<iostream>
using namespace std;

class Position {
public:
    int quantity;
    double price;
    
    Position(int q, double p) : quantity(q), price(p) {}
    
    long long getTotalValue() {
        return quantity * price;  // BUG! Overflow before cast!
    }
    
    double getAveragePrice(int totalQuantity) {
        return (quantity * price) / totalQuantity;  // BUG! Overflow!
    }
};

int main() {
    Position pos(1000000000000, 2500.0);
    
    cout << "Total Value: " << pos.getTotalValue() << endl;
    
    double avg = pos.getAveragePrice(500000);
    cout << "Average Price: " << avg << endl;
    
    return 0;
 }