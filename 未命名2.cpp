#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

void solve(){
	int n;
	cin >> n;
	int a[n+10];
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int x = a[1] * a[2];
	int y = a[n] * a[n-1];
	cout << max(x,y) << endl;
}

signed main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}
