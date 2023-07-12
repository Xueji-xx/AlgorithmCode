#include <iostream>
using namespace std;
#define int long long

void solve(){
    int n,x;
    cin>>n>>x;
    int l = n,r = 5e18+50;
    for(int i = 0;i < 60;i ++){
        int a = n >> i & 1,b = x >> i & 1;
        if(a == 0 && b == 1){
            cout<<-1<<endl;
            return;
        }
        int c = (n / ((long long)1 << i) + 1) * ((long long)1 << i);
        if(a == 1 && b == 0)l = max(l,c);
        else if(a == 1 && b == 1)r = min(r,c - 1);
    }
    cout<<(l <= r ? l : -1)<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}