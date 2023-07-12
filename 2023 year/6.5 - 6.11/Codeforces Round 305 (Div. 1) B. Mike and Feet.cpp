#include <iostream>
#include <stack>
using namespace std;
#define int long long
stack<int> s;
const int N = 2e5+5;
int a[N];
int l[N];
int r[N];
int ans[N];

signed main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		while(!s.empty() && a[s.top()] >= a[i])s.pop();
		if(!s.empty())l[i] = s.top() + 1;
		else l[i] = 1;
		s.push(i);
	}
	while(!s.empty())s.pop();
	for(int i = n;i >= 1;i --){
		while(!s.empty() && a[s.top()] >= a[i])s.pop();
		if(!s.empty())r[i] = s.top() - 1;
		else r[i] = n;
		s.push(i);
	}
	for(int i = 1;i <= n;i ++){
		ans[r[i] - l[i] + 1] = max(ans[r[i] - l[i] + 1] , a[i]);
	}
	for(int i = n;i >= 1;i --){
		ans[i] = max(ans[i+1],ans[i]);
	}
	for(int i = 1;i <= n;i ++)cout << ans[i] << ' ';
	return 0;
} 
