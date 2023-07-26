#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e6+10;

int t,n,tot;
int a[N],h[N];
int f[N][3];
struct Node{
	int v,next;
}e[N];

void add(int u,int v){
	e[++tot] = {v,h[u]};
	h[u] = tot;
}

void dfs(int u,int fa){
	f[u][0] = 0,f[u][1] = 0x3f3f3f3f,f[u][2] = a[u];
	for(int i=h[u];~i;i=e[i].next){
		int j = e[i].v;
		if(j == fa) continue;
		dfs(j,u);
		f[u][0] += min(f[j][1],f[j][2]);
		f[u][2] += min({f[j][0],f[j][1],f[j][2]});
	}
	for(int i=h[u];~i;i=e[i].next){
		int j = e[i].v;
		if(j == fa) continue;
		f[u][1] = min(f[u][1],f[u][0] + f[j][2] - min(f[j][1],f[j][2]));
	}
	if(f[u][0] == 0) f[u][0] = 0x3f3f3f3f;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		tot = -1;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=2*n;i++) h[i] = -1;
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
		cout << min(f[1][1],f[1][2]) << endl;
	}
}