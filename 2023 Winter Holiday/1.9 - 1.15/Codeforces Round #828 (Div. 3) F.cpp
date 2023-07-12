#include <iostream>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    int p[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        p[a[i]] = i;
    }
    int l,r;
    l = r = p[0];
    int ans = 1;
    for(int len = 2;len <= n;len ++){
        int i = (len - 1) / 2;
        l = min(l,p[i]);
        l = min(l,n - len + 1);
        r = max(r,p[i]);
        r = max(r,len);
        ans += max((int)0,len - (r - l));
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}