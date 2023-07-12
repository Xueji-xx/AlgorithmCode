#include <iostream>
using namespace std;

#define int long long

void solve(){
    int n,s;
    cin>>n>>s;
    int a[n+10];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    int dp[n+10][5];
    for(int i = 0;i <= n;i ++)dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 1e18;
    dp[1][3] = 0;
    for(int i = 2;i <= n;i ++){
        int a1[4] = {0,s,a[i-1] - s,a[i-1]};
        int a2[4] = {0,s,a[i] - s,a[i]};
        for(int j = 0;j <= 3;j ++){
            for(int k = 0;k <= 3;k ++){
                if(i != n){
                    if(a[i] > s && (k == 0 || k == 3))continue;
                    if(a[i] < s && (k == 1 || k == 2))continue;
                }
                dp[i][k] = min(dp[i][k],dp[i-1][j] + a1[j] * (a[i] - a2[k]));
            }
        }
    }
    cout<<dp[n][0]<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}