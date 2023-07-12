#include<iostream>
#include<iomanip>
using namespace std;
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
double ans = 0;

bool check(double mid,int n){
	double l = -1e9, r = 1e9;
	for (int i = 1; i <= n; i++){
		if (mid < b[i])
			return false;
		else{
			l = max(l, a[i] + b[i] - mid);
			r = min(r, a[i] + mid - b[i]);
		}
	}
	ans = l;
	return r+(1e-8) >= l;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int i = 1; i <= n; i++)cin >> b[i];
		double l = 0, r = 1e9;
		for (int i = 0; i < 100; i++){
			double mid = (l + r) / 2;
			if (check(mid,n))r = mid;
			else l = mid;
		}
		check(l,n);
		cout <<fixed<<setprecision(7)<< ans<< endl;
	}
    system("pause");
	return 0;
}