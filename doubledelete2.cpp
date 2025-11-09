#include <iostream>
#include<memory>
#include<vector>

using namespace std;

class Order{
    private:
    string s;
    
    public:
    Order(string s):s(s){
        //this->s = s;
        cout<<"Order Const: "<<s<<endl;
    }
};


class OrderBook {
    vector<Order*> orders;
    
public:
    void addOrder(Order* order) {
        orders.push_back(order);
    }
    
    ~OrderBook() {
        int count = 0;
        for (Order* order : orders) {
            count++;
            cout<<"OrderBook Dest: "<<count<<endl;
            delete order;  // Delete 1
        }
    }
};

int main() {
    Order* order = new Order("ORD001");
    
    OrderBook book;
    book.addOrder(order);
    
    // OrderBook destructor deletes order (Delete 1)
    
    //delete order;  // Delete 2 - DOUBLE DELETE!
}