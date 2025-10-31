#include<vector>
#include<memory>
#include<iostream>
using namespace std;

class SmartPointer {
private:
    unique_ptr<int> ptr; // unique_ptr to manage the integer resource   
public:
    // Constructor  
    SmartPointer(int value) : ptr(make_unique<int>(value)) {
        cout << "SmartPointer constructed with value: " << *ptr << endl;
    }

    // Move Constructor
    SmartPointer(SmartPointer&& other) noexcept : ptr(move(other.ptr)) {
        cout << "SmartPointer moved." << endl;
    }

    // Deleted Copy Constructor
    SmartPointer(const SmartPointer& other) = delete;

    // Move Assignment Operator
    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            ptr = move(other.ptr);
            cout << "SmartPointer move-assigned." << endl;
        }

        return *this;
    }

    // Deleted Copy Assignment Operator
    SmartPointer& operator=(const SmartPointer& other) = delete;

    // Function to get the value
    int getValue() const {
        return ptr ? *ptr : 0; // Return 0 if ptr is null
    }

    // Destructor
    ~SmartPointer() {
        cout << "SmartPointer with value " << (ptr ? to_string(*ptr) : "null") << " destroyed." << endl;
    }

};  


int main() {
    SmartPointer sp1(42); // Create a SmartPointer
    cout << "Value in sp1: " << sp1.getValue() << endl;

    SmartPointer sp2 = move(sp1); // Move sp1 to sp2
    cout << "Value in sp2 after move: " << sp2.getValue() << endl;
    cout << "Value in sp1 after move: " << sp1.getValue() << endl; // sp1 is now in a valid but unspecified state

    SmartPointer sp3(100);
    sp3 = move(sp2); // Move-assign sp2 to sp3
    cout << "Value in sp3 after move-assignment: " << sp3.getValue() << endl;
    cout << "Value in sp2 after move-assignment: " << sp2.getValue() << endl; // sp2 is now in a valid but unspecified state

    return 0;
}