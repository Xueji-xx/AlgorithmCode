#include<iostream>
#include<cmath>
#define int long long
using namespace std;

void solve(){
    int p,q;
    cin>>p>>q;
    int x = sqrt(p*p - 4*q*q);
    if(x * x == p * p - 4 *     q * q){
        cout<<p+x<<' '<<2*q<<endl;
    }
    else cout<<0<<' '<<0<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}