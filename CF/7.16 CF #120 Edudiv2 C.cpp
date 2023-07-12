#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long inf = 1e18;

void solve(){
	int n;
	cin>>n;
	long long k;
	cin>>k;
	vector<long long> v(n);
	for(int i = 0;i < n;i ++)cin>>v[i];
	sort(v.begin(),v.end());
	vector<long long> sum(n);
	sum[0] = v[0];
	for(int i = 1;i < n;i ++)sum[i] = sum[i-1] + v[i];
	long long ans = inf;
	for(int i = 0;i < n;i ++){
		long long x = i;
		long long y = sum[n-i-1]+v[0]*i;
		if(y > k){
			x += (y - k + i)/(i+1);
		}
		ans = min(ans,x);
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
