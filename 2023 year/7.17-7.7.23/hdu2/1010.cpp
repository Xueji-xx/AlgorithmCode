#include <iostream>
#include <climits>
using namespace std;

const int N = 2050;
const int INF = 0x3f3f3f3f;
int dp[N][N],sum[N][N];
const int M = 1e6+50;
int a[M],pos[M];

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i <= m;i ++){
        for(int j = 0;j <= m;j ++){
            dp[i][j] = sum[i][j] = INF;
        }
    }
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        pos[i] = i % m;
    }
    int ans = INF;
    for(int i = 2;i <= m;i ++){
        for(int j = 1;j <= i - 1;j ++){
            dp[pos[i]][j] = a[i] + a[i-j];
            sum[pos[i]][j] = min(sum[pos[i]][j-1],dp[pos[i]][j]);
        }
    }
    for(int i = m + 1;i <= n;i ++){
        for(int j = 1;j <= m-1;j ++){
            int k = i - j;
            dp[pos[i]][j] = a[i] + sum[pos[k]][k - (i - m)];
            sum[pos[i]][j] = min(sum[pos[i]][j-1],dp[pos[i]][j]);
        }
    }
    for(int i = n - m + 2;i <= n;i ++){
        int s = n - m + 1;
        for(int j = 1;j <= i - s;j ++){
            ans = min(ans,sum[pos[i]][j]);
        }
    }
    cout << ans << endl;
}


int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}