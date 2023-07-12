#include<iostream>
using namespace std;
int dp[50][50];
int a[50];


int main(){
	int n;
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		dp[i][i] = a[i];
	}
	int maxm = dp[1][1];
	for(int len = 2;len <= n;len ++){
		for(int i = 1;i <= n - len + 1;i ++){
			int j = i + len - 1;
			if(j > n)break;
			for(int k = i;k < j;k ++){
				if(dp[i][k] == dp[k+1][j] && dp[i][k] != 0 && dp[k+1][j] != 0){
					dp[i][j] = max(dp[i][j],dp[i][k]+1);maxm = max(maxm,dp[i][j]);
				}
			}
		}
	}
	cout<<maxm<<endl;
	return 0;
} 
