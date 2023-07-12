#include<iostream>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i < n;i ++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	long long sum = 0;
	for(int i = 0;i < m;i ++){
		int x;
		cin>>x;
		sum += x;
	}
	cout<<a[sum%n]<<endl;
}



int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
