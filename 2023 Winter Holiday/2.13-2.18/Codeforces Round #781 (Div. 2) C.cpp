#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 3e5+50;
int a[N];

void solve(){
	int ans = 1;
	int n;
	cin>>n;
	for(int i = 2;i <= n;i ++){
		int x;
		cin>>x;
		a[x]++;
	}
	sort(a+1,a+1+n,greater<int>());
	priority_queue<int,vector<int>,less<int>>h;
	for(int i = 1;i <= n;i ++){
		if(a[i]){
			ans++;
			h.push(a[i] + i - 1);
			a[i] = 0;
		}
		else break;
	}
	while(ans < h.top()){
		int x = h.top() - 1;
		h.pop();
		h.push(x);
		ans++;
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
