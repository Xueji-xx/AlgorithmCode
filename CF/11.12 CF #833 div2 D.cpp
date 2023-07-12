#include <iostream>
using namespace std;
typedef long long ll;

void solve(){
    ll a,b,d;
    cin>>a>>b>>d;
    a = a | b;
    if(a % d == 0){
        cout << a << endl;
        
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}