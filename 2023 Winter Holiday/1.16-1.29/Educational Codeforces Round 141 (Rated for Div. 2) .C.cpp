#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
#define ll long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    auto b = a;
    sort(b.begin()+1,b.end());
    vector<int> sum(n+1);
    for(int i = 1;i <= n;i ++){
        sum[i] = sum[i-1] + b[i];
    }
    int ans = n + 1;
    for(int i = 1;i <= n;i ++){
        if(m >= sum[i])ans = min(ans,n - i + 1);
        if(i < n && m >= sum[i] + max(a[i+1] - b[i],0ll))ans = min(ans,n - i);
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