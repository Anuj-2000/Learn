#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    //base case
    if (n==0) return;
    //bake recusrion sambhal lega
    printArr(arr,n-1);
     //1st case
    cout<<arr[n-1]<<" ";
}

int fibb( int n){
    //base case
    if (n==0 || n==1) return n;
    int res = fibb(n-1) + fibb(n-2);
    

}


int main(){
    int arr[] = {10,20,30,40,50};
    printArr(arr,5); 
    fibb(5);
}