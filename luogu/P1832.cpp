#include<iostream>
using namespace std;
#define ll long long
ll pri[1050],ispri[1050];
ll cnt,n;
ll dp[1050];

void prime(){
	for(int i = 2;i <= n;i ++){
		if(!ispri[i])pri[cnt++] = i;
		for(int j = 0;j < cnt;j ++){
			if(i*pri[j] > n)break;
			ispri[i*pri[j]] = 1;
			if(i % pri[j] == 0)break;
		}
	}
}



int main(){
	cin>>n;
	prime();
	dp[0] = 1;
	for(int i = 0;i < cnt;i++){
		for(int j = pri[i];j <= n;j ++){
			dp[j] = dp[j] + dp[j-pri[i]];
		}
	}
	cout<<dp[n];
	return 0;
} 
