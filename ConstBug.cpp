#include<iostream>
#include<vector>
#include<map>
using namespace std;


class PositionManager {
private:
    map<string, double> positions;  // symbol -> net position
    
public:
    void updatePosition(const string& symbol, double quantity) {
        positions[symbol] += quantity;
    }
    
    bool isOverLimit(const string& symbol, double limit) {
        // BUG! Creates entry if checking symbol not in portfolio
        return positions[symbol] > limit;
    }
    
    void checkAllLimits(double limit) {
        vector<string> symbols = {"RELIANCE", "TCS", "INFY", "WIPRO", "HDFC"};
        
        cout << "Checking position limits..." << endl;
        for (const auto& symbol : symbols) {
            if (isOverLimit(symbol, limit)) {
                cout << symbol << " is over limit!" << endl;
            }
        }
    }
    
    void displayPositions() {
        cout << "\nCurrent Positions:" << endl;
        for (const auto& [symbol, pos] : positions) {
            cout << "  " << symbol << ": " << pos << endl;
        }
        cout << "Total symbols: " << positions.size() << endl;
    }
};

int main() {
    PositionManager pm;
    
    // Add positions for 2 symbols
    pm.updatePosition("RELIANCE", 1000);
    pm.updatePosition("TCS", 500);
    
    cout << "After adding positions:" << endl;
    pm.displayPositions();
    
    // Check limits for all symbols (including ones we don't have!)
    pm.checkAllLimits(2000);
    
    cout << "\nAfter checking limits:" << endl;
    pm.displayPositions();  // BUG! All 5 symbols added with 0!
    
    return 0;
}