#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex orderMutex;
mutex positionMutex;

void processOrder() {
    cout << "Thread 1: Locking order..." << endl;
    lock_guard<mutex> lock1(orderMutex);
    
    cout << "Thread 1: Processing order..." << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    
    cout << "Thread 1: Need position lock..." << endl;
    lock_guard<mutex> lock2(positionMutex);  // Wait for Thread 2!
    
    cout << "Thread 1: Done" << endl;
}

void updatePosition() {
    cout << "Thread 2: Locking position..." << endl;
    lock_guard<mutex> lock2(orderMutex);  // Wait for Thread 1!
    // lock_guard<mutex> lock1(positionMutex);
    
    cout << "Thread 2: Updating position..." << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
    
    cout << "Thread 2: Need order lock..." << endl;
    lock_guard<mutex> lock1(positionMutex);
    // lock_guard<mutex> lock2(orderMutex);  // Wait for Thread 1!
    
    cout << "Thread 2: Done" << endl;
}

int main() {
    thread t1(processOrder);
    thread t2(updatePosition);
    
    t1.join();  // Will never finish!
    t2.join();  // Will never finish!
    
    cout << "Program done" << endl;  // Never reaches here!
    
    return 0;
}