#include <iostream>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5+50;
int v[N];int n;
int sum[N];
int dp[N];

void solve(){
    dp[1] = v[1];
    sum[1] = v[1];
    for(int i = 2;i <= n;i ++){
        sum[i] = v[i] + sum[i-1];
        int l = dp[i-1],r = 1e9;
        while(l < r){
            int mid = l + r >> 1;
            if(mid * i - sum[i-1] >= v[i])r = mid;
            else l = mid+1;
        }
        dp[i] = l;
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> v[i];
    }
    solve();
    int q;
    cin >> q;
    while(q --){
        int x;
        cin >> x;
        int ans = sum[n] / x;
        if(sum[n] % x)ans ++;
        if(ans <= n && dp[ans] <= x)cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}