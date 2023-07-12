#include<iostream>
#define ll long long
using namespace std;
const int N = 5050;
int a[N],b[N],map[N][N],dp[N];

int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i ++){
		cin>>a[i];
	}
	for(int i = 0;i < n;i ++){
		cin>>b[i];
	}
	for(int i = 0;i < n;i ++)map[i][i] = a[i]*b[i];
	dp[0] = a[0]*b[0];
	for(int i = 1;i < n;i ++){
		dp[i] = a[i]*b[i] + dp[i-1];
		for(int j = 0;j < i;j ++){
			map[i][j] = map[i-1][j+1] + a[i]*b[j] + a[j]*b[i];
			dp[i] = max(dp[i],map[i][j] + dp[j-1]);
		}
	}
	cout<<dp[n-1];
	return 0;
}
