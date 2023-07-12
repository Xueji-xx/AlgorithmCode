#include <iostream>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
	int n,k;
	cin>>n>>k;
	int a[n+10] = {0};
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	int sum = 0;
	int ans = 0;
	a[0] = k;
	for(int i = 0;i < n;i ++){
		int x = sum;
		for(int j = i+1;j <= min(n,i + 32);j ++){
			int cnt = a[j];
			cnt >>= j-i;
			x += cnt;
		}
		ans = max(ans,x);
		sum += a[i+1] - k;
	}
	ans = max(ans,sum);
	cout<<ans<<endl;
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
