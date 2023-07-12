#include <iostream>
using namespace std;

const int N = 550;
int dp[N][N];
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        dp[i][i] = 1;
        if(a[i-1] == a[i])dp[i-1][i] = 1;
        else dp[i-1][i] = 2;
    }
    for(int len = 3;len <= n;len ++){
        for(int l = 1;l + len - 1 <= n;l ++){
            int r = l + len - 1;
            dp[l][r] = n;
            for(int k = l;k < r;k ++){
                dp[l][r] = min(dp[l][r],dp[l][k] + dp[k+1][r]); 
            }
            if(a[l] == a[r])dp[l][r] = min(dp[l][r],dp[l+1][r-1]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}