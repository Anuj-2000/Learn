#include<iostream>
#include<vector>
using namespace std;

class OrderBook {
public:
    vector<double> bidPrices = {2503.00, 2499.50, 2499.00};
    vector<double> askPrices = {2501.00, 2501.50, 2502.00};
    
    void displayBestPrices() {
        cout << "Best Bid: " << bidPrices[0] << endl;
        cout << "Best Ask: " << askPrices[0] << endl;
    }
    
    void matchOrders() {
        // Check all bid levels against all ask levels
        for (size_t i = 0; i < bidPrices.size(); i++) {  // BUG: <=
            for (size_t j = 0; j < askPrices.size(); j++) {  // BUG: <=
                if (bidPrices[i] >= askPrices[j]) {
                    cout << "Match possible: Bid " << bidPrices[i] 
                         << " >= Ask " << askPrices[j] << endl;
                }
            }
        }
    }
};

int main() {
    OrderBook book;
    book.displayBestPrices();
    
    cout << "\n=== Matching Orders ===" << endl;
    book.matchOrders();  // Will crash or show garbage
    
    return 0;
}