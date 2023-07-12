#include <iostream>
#include <vector>
using namespace std;
#define int long long

const int N = 100010;
int n,k,cnt;
int ans,g[N];
char a[N],b[N];
vector<char> tol;
bool vis[26],st[26];




void init(){
	for(int i = 1;i <= N - 10;i ++){
		g[i] = (i + 1) * i / 2;
	}
}

void dfs(int u){
	if(cnt >= min((int)tol.size(),k)){
		int tmp = 0;
		for(int i = 0;i < n;i ++){
			if(!st[a[i] - 'a'] && a[i] != b[i])continue;
			int j = i;
			while(j < n && (st[a[j] - 'a'] || a[j] == b[j]))j ++;
			int len = j - i;
			tmp += g[len];
			i = j;
		}
		ans = max(ans,tmp);
		return;
	}
	for(int i = u + 1;i < tol.size();i ++){
		if(!st[tol[i] - 'a']){
			st[tol[i] - 'a'] = true;
			cnt++;
			dfs(i);
			cnt--;
			st[tol[i] - 'a'] = false;
		}
	}
}

void solve(){
	ans = cnt = 0;
	for(int i = 0;i < 26;i ++){
		vis[i] = st[i] = false;
	}
	tol.clear();
	cin>>n>>k;
	cin>>a>>b;
	for(int i = 0;i < n;i ++){
		if(!vis[a[i] - 'a'] && a[i] != b[i]){
			vis[a[i] - 'a'] = true;
			tol.push_back(a[i]);
		}
	}
	dfs(-1);
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
