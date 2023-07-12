#include <iostream>
using namespace std;
#define int long long

void solve(){
	int n;
	cin>>n;
	int a[n+10];
	int b[n+10];
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		b[i] = 0;
	}
	int ans = 0,res;
	int sum[n+10] = {0};
	for(int i = 2;i < n;i ++){
		b[a[i-1]]++;
		for(int j = 1;j <= n;j ++){
			sum[j] = sum[j-1] + b[j];
		}
		res = sum[a[i+1]];
		for(int j = i + 2;j <= n;j ++){
			if(a[i] > a[j])ans += res;
			res += sum[a[j]];
		}
	}
	cout<<ans<<endl;
}

signed main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
