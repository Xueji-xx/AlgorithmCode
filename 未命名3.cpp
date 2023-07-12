#include <iostream>
using namespace std;

#define int long long

signed main(){
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		if(n == 4){
			cout << 26 << endl;
			continue;
		}
		int x = 2 * (n-5);
		int ans = 26 + 11 * (n - 4) + x*(n - 4)/2;
		cout << ans << endl;
	}
	return 0;
}
