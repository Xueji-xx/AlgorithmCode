#include<iostream>
#include<string.h>
#include<vector>
#define int long long
using namespace std;
const int N = 1e5+50;
const int mod = 998244353;
vector<int> g[N];
int cnt; 
int sum[N];
void dfs(int u,int fa){
    int len = (int)g[u].size();
    sum[u] = 1;
    for(int i = 0;i < len;i ++){
        int v = g[u][i];
        if(v == fa)continue;
        dfs(v,u);
        sum[u] += sum[v];
    }
    if(sum[u] % 2 == 0 && u != 1)cnt++;
}


void solve(){
    memset(sum,0,sizeof sum);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++)g[i].clear();
    for(int i = 0;i < n-1;i ++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt = 0;
    dfs(1,0);
    int ans = 1;
    for(int i = 1;i <= cnt;i ++){
		ans = ans * 2 % mod;	
	}
	cout<<ans-1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
