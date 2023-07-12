#include <iostream>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    int l = 1,r = l;
    int ans = 0;
    for(int l = 1;l <= n;l ++){
        while(a[r] >= r - l + 1 && r <= n)r ++;
        ans += r - l;
    }
    cout<<ans<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}