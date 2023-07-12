#include<iostream>
using namespace std;
const int MOD = 200907;
#define int long long

int qmi(int a,int b,int k){
    int res = 1;
    while(b){
        if(b & 1)res = res * a % k;
        a = a * a % k;
        b >>= 1;
    }
    return res;
}


void solve(){
    int a,b,c;
    int k;
    cin>>a>>b>>c>>k;
    if(c / b == b / a && (c % b == 0) && (b % a == 0)){
        int q = c / b;
        int x = qmi(q,k-1,MOD);
        cout<<a * x % MOD<<endl;
    }
    else{
        cout<<(a + (k-1)*(b-a) % MOD) % MOD<<endl;
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}