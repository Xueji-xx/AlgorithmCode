#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    if(n % 4 == 0 || n & 1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}