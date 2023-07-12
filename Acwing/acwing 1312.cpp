#include<iostream>
using namespace std;
#define int long long
const int p = 1e6+3;

int qmi(int a,int b,int p){
    int res = 1;
    while(b){
        if(b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int C(int a,int b){
    int up = 1,down = 1;
    for(int i = a,j = 1;j <= b;j ++,i --){
        up = up * i % p;
        down = down * j % p;
    }
    return up * qmi(down,p - 2,p);
}

int lucas(int a,int b){
    if(a < p && b < p)return C(a,b);
    return C(a % p,b % p)*lucas(a / p, b / p) % p;
}

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    cout<<(lucas(r - l + 1 + n,r - l + 1) - 1 + p) % p<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}