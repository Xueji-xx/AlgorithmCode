#include<iostream>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i = (n+2)/3;i <= 2*n;i ++){
        if((i & 1) && i <= n)ans++;
        if(!(i & 1) && i >= n+1)ans++;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}