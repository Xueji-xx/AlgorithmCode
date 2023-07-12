#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int blue[n+10] = {0};
    for(int i = 1;i <= n;i ++)cin>>blue[i];
    int m;
    cin>>m;
    int red[m+10] = {0};
    for(int i = 1;i <= m;i ++)cin>>red[i];
    int x = max(n,m);
    int dp[x+10] = {0};
    for(int i = 1;i <= x;i ++){
        if(i <= n && i <= m){
            dp[i] += max(red[i],blue[i]) + dp[i-1];
        }
        else if(i > n){
            dp[i] += red[i] + dp[i-1];
        }
        else dp[i] += blue[i] + dp[i-1];
    }
    int ans = INT_MAX;
    for(int i = 1;i <= max(n,m);i ++){
        cout<<dp[i]<<' ';
        ans = min(ans,dp[i]);
    }
    cout<<endl;
    cout<<ans<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}