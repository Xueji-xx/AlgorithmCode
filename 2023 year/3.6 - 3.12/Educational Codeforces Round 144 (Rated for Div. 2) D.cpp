#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define int long long
const int N = 1e6+50;
const int INF = 1e18;

int n,k,x;
int a[N];
int work(int len,int add){
    int res = 0;
    vector<int> pre(n+2,-INF);
    for(int i = 1;i <= n;i ++)pre[i] = max(a[i] - add,pre[i-1] + a[i] - add);
    for(int i = 1;i <= n - len + 1;i ++){
        vector<int> dp(k+1,-INF);
        dp[0] = pre[i-1];
        for(int j = 1;j <= k;j ++){
            dp[j] = max(dp[j-1] + a[i + j-1] + x,a[i+j-1] + x);
            res = max(res,dp[j]);
        }
    }
    return res;
}

void solve(){
    cin>>n>>k>>x;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    int ans = 0;
    if(k == 0){
        vector<int> dp(n+1,-INF);
        for(int i = 1;i <= n;i ++){
            dp[i] = max(a[i] - x,dp[i-1] + a[i] - x);
            ans = max(ans,dp[i]);
        }
        cout<<ans<<endl;
        return;
    }
    else if(x >= 0){
        cout<<work(k,x)<<endl;
    }
    else{
        for(int l = 0;l <= k;l ++){
            int r = k - l;
            r = n - r + 1;
            vector<int> dp(n+1,-INF);
            for(int i = 1;i <= n;i ++){
                if(i <= l || i >= r)dp[i] = max(dp[i-1] + a[i] + x,a[i] + x);
                else dp[i] = max(dp[i-1] + a[i] - x,a[i] - x);
                ans = max(ans,dp[i]);
            }
        }
        cout<<ans<<endl;
    }
    return;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}