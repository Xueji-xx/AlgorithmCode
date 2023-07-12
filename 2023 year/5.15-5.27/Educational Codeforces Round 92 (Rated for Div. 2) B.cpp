#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e5+50;
int dp[N][10];

void solve(){
    memset(dp,0,sizeof dp);
    int n,k,z;
    cin >> n >> k >> z;
    int a[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 2;i <= n;i ++){
        dp[i][0] = dp[i-1][0] + a[i];
        if(i - 1 == k)ans = max(ans,dp[i][0]);
        for(int q = 1;q <= z;q ++){
            for(int j = 0;j <= q;j ++){
                int s = j *(a[i] + a[i-1]);
                dp[i][q] = max(dp[i][q],dp[i-1][q-j] + s + a[i]);
                if(i - 1 + q * 2 == k)ans = max(ans,dp[i][q]);
                if(i - 1 + q * 2 == k + 1)ans = max(ans,dp[i][q]-a[i]);
            }
        }
    }
    cout << ans + a[1] << endl;
}


int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}