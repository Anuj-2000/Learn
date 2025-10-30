#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v1 = {1,2,3,4,5};

    //copies the contents of v1 into v2
    vector<int> v2 = v1;
    cout<<"v1: "<<v1.size()<<endl;
    cout<<"v2: "<<v2.size()<<endl;

    //moves the contents of v1 into v3
    vector<int> v3 = move(v1);
    cout<<"v1: "<<v1.size()<<endl;
    cout<<"v3: "<<v3.size()<<endl;
}