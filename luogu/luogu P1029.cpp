#include<iostream>
#include<cmath>
using namespace std;
#define ll long long 

ll gcd(ll a,ll b){
    return b?gcd(b,a % b):a;
}


int main(){
    ll x,y;
    cin>>x>>y;
    ll ans = 0;
    if(x == y)ans--;
    y *= x;
    for(ll i = 1;i <= sqrt(y);i ++){
        if((y % i == 0) && gcd(i,y/i) == x)ans += 2;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}