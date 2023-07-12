#include<iostream>
using namespace std;
#define int long long

int slow_mul(int a,int b,int mod){
    int ans = 0;
    while(b){
        if(b & 1){
            ans = (ans + a)%mod;
        }
        a = a * 2 % mod;
        b >>= 1;
    }
    return ans;
}


signed main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<slow_mul(a,b,c);
    return 0;
}