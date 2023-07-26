#include<iostream>
using namespace std;
#define int long long
const int N = 1e6+10;

int n;
int dp[N][2],a[N],b[N];

signed main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	if(b[1]) dp[1][1] = a[1]*b[1];
    for(int i=2;i<=n;i++){
		if(b[i]){
			dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + a[i];
			dp[i][0] = dp[i-1][0] + a[i-1];
		}else {
			if(b[i-2])
				dp[i][1] = max(max(dp[i-1][0],dp[i-1][1]) + b[i-1]*(a[i] - a[i-1]),max(dp[i-1][0],dp[i-1][1]) + b[i-1]*(a[i] - a[i-2]));
			else
				dp[i][1] = max(dp[i-1][1] + b[i-1]*(a[i] - a[i-1]),dp[i-1][0] + b[i-1]*(a[i] - a[i-2]));
			dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
		}
	}
	cout << max(dp[n][0],dp[n][1]) << endl;
}
