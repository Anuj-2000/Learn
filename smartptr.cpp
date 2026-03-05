#include<iostream>
#include<memory>
Using namespace std;

int main(){
    unique_ptr<int> p1 = make_unique(23);
    cout<<*p1;
}