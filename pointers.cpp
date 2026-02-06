#include <iostream>
#include <memory>
using namespace std;

// Exercise 1: Pointer basics
void swapUsingPointers(int* a, int* b) {
    // TODO: Implement swap using pointers
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp;
    
    cout<<*a<<" "<<*b<<endl;
}

// Exercise 2: Const correctness
void printArray(const int* arr, int size) {
    // TODO: Print array without modifying it
}

// Exercise 3: Double pointer
void allocate2DArray(int*** arr, int rows, int cols) {
    // TODO: Allocate 2D array dynamically
}

// Exercise 4: Function pointer
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

void calculate(int a, int b, int (*operation)(int, int)) {
    // TODO: Use function pointer to perform operation
}

int main() {
    // Test all functions
    int a = 10;
    int* p = &a;
    int b = 13;
    int* q = &b;

    swapUsingPointers(p,q);
    
    // Exercise 5: Memory leak detection
    // TODO: Intentionally create a leak, then fix it
    int* leak = new int[100];
    // Fix: 
    delete[] leak;   
    return 0;
}