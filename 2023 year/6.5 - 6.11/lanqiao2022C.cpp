#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5+50;
int n,m;
struct T {
	int a;int b;
	int i;
};

T t[N];

bool cmp(T x,T y){
	if(x.a == y.a)return x.b < y.b;
	return x.a < y.a;
}

bool check(int x){
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		if(x - t[i].a <= t[i].b){
			ans += max((long long)0,x - t[i].a);
		}
		else return true;
	}
	if(m >= ans)return false;
	return true;
}

signed main(){
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)cin >> t[i].a;
	for(int i = 1;i <= n;i ++)cin >> t[i].b;
	for(int i = 1;i <= n;i ++)t[i].i = i;
	sort(t+1,t+1+n,cmp);
	int l = t[1].a,r = 9999999;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid))r = mid - 1;
		else l = mid + 1;
	}
	if(l == 1){
		cout << t[1].a;
	}
	else cout << l - 1 << endl;
	return 0;
} 
