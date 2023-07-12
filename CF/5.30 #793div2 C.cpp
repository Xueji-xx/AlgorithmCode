#include<iostream>
#include<algorithm>
using namespace std;
#include<map>
void solve(){
	map<int,int> a;
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 0;i < n;i ++){
		int x;
		cin>>x;
		a[x]++;
		if(a[x] <= 2)ans++;
	}
	cout<<(ans-1)/2+1<<endl;
}



int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
