#include<iostream>
#include<string.h>
using namespace std;
const int N = 300;
int dp[400][400];
int n;
int sum[500],a[500];

int main(){
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		sum[i] += sum[i-1] + a[i];
	}
	memset(dp,0x3f3f3f,sizeof dp);
	for(int len = 1;len <= n;len ++){
		for(int i = 1; i + len - 1 <= n;i ++){
			int j = i + len - 1;
			if(len == 1){
				dp[i][j] = 0;
				continue;
			}
			for(int k = i;k <= j - 1;k ++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
} 
