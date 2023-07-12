#include<iostream>
using namespace std;
int n,k;
int ans;
void dfs(int a,int sum,int cnt){
	if(sum == 1){
		ans++;
		return;
	}
	for(int i = a;i <= cnt/sum;i ++){
		dfs(i,sum-1,cnt-i);
	}
}

int main(){

	cin>>n>>k;
	dfs(1,k,n);
	cout<<ans;
	return 0;
}
