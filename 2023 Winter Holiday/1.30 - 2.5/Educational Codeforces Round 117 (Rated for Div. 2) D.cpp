#include <iostream>
using namespace std;
#define int long long
void solve(){
    int a,b,x;
    cin>>a>>b>>x;
    while(a && b){
        if(a < b)swap(a,b);
        if(a % b == x % b && a >= x){
            cout<<"YES"<<endl;
            return;
        }
        a %= b;
    }
    cout<<"NO"<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}