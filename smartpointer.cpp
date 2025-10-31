#include<iostream>
#include<memory>

using namespace std;

int main(){

    unique_ptr<int> p1 = make_unique<int> (10);
    unique_ptr<int> p2 = move(p1);

    shared_ptr<int> p3 = make_unique<int> (20);
    shared_ptr<int> p4 = p3;

    cout<<"Ref count: "<< p3.use_count()<<endl;

}