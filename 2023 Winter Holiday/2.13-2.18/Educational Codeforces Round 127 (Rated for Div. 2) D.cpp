#include <iostream>
using namespace std;

void solve(){
	int n,x;
	cin>>n>>x;
	int minn = INT_MAX;
	int maxm = -INT_MAX;
	int a[n+10];
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		minn = min(a[i],minn);
		maxm = max(maxm,a[i]);
	}
	int res = 0;
	for(int i = 2;i <= n;i ++){
		res += abs(a[i] - a[i-1]);
	}
	int t_1 = min(abs(a[1] - 1),abs(a[n] - 1));
	int t_x = min(abs(a[1] - x),abs(a[n] - x));
	for(int i = 2;i <= n;i++){
		t_1 = min(t_1,abs(a[i-1] - 1) + abs(a[i] - 1) - abs(a[i] - a[i-1]));
		t_x = min(t_x,abs(a[i-1] - x) + abs(a[i] - x) - abs(a[i] - a[i-1]));
	}
	if(minn > 1){
		res += t_1;
	}
	if(x > maxm){
		res += t_x;
	}
	cout<<res<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin>>t;
	while(t--)solve();
	return 0;
}
