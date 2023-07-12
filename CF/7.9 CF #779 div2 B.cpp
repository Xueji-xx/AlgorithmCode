#include<iostream>
using namespace std;
#define ll long long
const ll mod = 998244353;
void solve(){
    int n;
    cin>>n;
    if(n & 1){
        cout<<0<<endl;
    }
    else{
        ll ans = 1;
        int y = n/2;
        for(int i = y;i > 0;i --){
            ans = (ans * i)%mod;
        }
        ll x = (ans*ans)%mod;
        cout<<x<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");    
    return 0;
}