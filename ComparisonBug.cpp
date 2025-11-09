#include <iostream>
#include <iomanip>
using namespace std;

class PriceValidator {
public:
    bool isPriceInRange(double price, double minPrice, double maxPrice) {
        return price >= minPrice && price <= maxPrice;  // Seems OK?
    }
    
    void validateOrder(double orderPrice) {
        double minAllowed = 2499.00;
        double maxAllowed = 2501.00;
        
        // Calculate price from components
        double calculatedPrice = 2500.00;
        double commission = 0.50;
        double tax = 0.50;
        double finalPrice = calculatedPrice - commission - tax;  // Should be 2499.00
        
        cout << fixed << setprecision(10);
        cout << "Final Price: " << finalPrice << endl;
        cout << "Min Allowed: " << minAllowed << endl;
        
        if (finalPrice == minAllowed) {  // BUG: Using ==
            cout << "Price exactly at minimum" << endl;
        } else if (finalPrice < minAllowed) {
            cout << "Price below minimum - REJECT" << endl;
        } else {
            cout << "Price OK" << endl;
        }
    }
};

int main() {
    PriceValidator validator;
    validator.validateOrder(2499.00);
    return 0;
}