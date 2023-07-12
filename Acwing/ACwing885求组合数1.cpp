#include<iostream>
using namespace std;
const int mod = 1e9+7;
int dp[2050][2050];

void init(){
	for(int i = 0;i < 2050;i ++){
		for(int j = 0;j <= i;j ++){
			if(!j)dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
		}
	}
}

int main(){
	int n;
	cin>>n;
	init();
	while(n--){
		int a,b;
		cin>>a>>b;
		cout<<dp[a][b]<<endl;;
	}
	
	return 0;
} 
