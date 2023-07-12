#include <iostream>
#include <math.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    int a,b;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        if(x < k){
            cout<<"Python 3."<<i<<" will be faster than C++";
            return 0;
        }
        if(i == n-1){
            a = x;
        }
        if(i == n)b = x;
    }
    if(a <= b)cout<<"Python will never be faster than C++";
    else cout<<"Python 3."<<n+floor(abs(k - a) / abs(b - a))<<" will be faster than C++";
    return 0;
}