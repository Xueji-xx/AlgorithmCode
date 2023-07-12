#include<iostream>
#include<cmath>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n+5];
    int b[n+5];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++)b[i] = a[i] - a[i-1];
    long long p = 0,q = 0;
    for(int i = 2;i <= n;i ++){
        if(b[i] > 0)p += b[i];
        else q -= b[i];
    }
    cout<<maxm(q,p)<<endl;
    cout<<abs(p - q) + 1 <<endl;
    return 0;
}