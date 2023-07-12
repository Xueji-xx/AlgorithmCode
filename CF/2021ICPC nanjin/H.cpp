#include<iostream>
#include<vector>
#include<set>
#include<climits>
#define endl '\n'
using namespace std;
#define int long long

const int MAXM = 1e6+50;
vector<int> g[MAXM];
int n,u,v;
int a[MAXM];
int f[MAXM],sum[MAXM],t[MAXM];//dp方程，取得的总和，晶蝶逃离时间

void dfs(int u,int fa){
    int maxm = 0;
    multiset<int> s;//找到 t = 3 的情况
    for(int v : g[u]){
        if(v == fa)continue;
        dfs(v,u);
        sum[u] += f[v];
        maxm = max(maxm,a[v]);
        if(t[v] == 3)s.insert(a[v]);
    }
    f[u] = sum[u] + maxm;
    s.insert(-LONG_LONG_MAX);
    for(int v : g[u]){
        if(v == fa)continue;
        if(t[v] == 3)s.erase(s.find(a[v]));
        f[u] = max(f[u],sum[u] - f[v] + a[v] + sum[v] + *s.rbegin());
        if(t[v] == 3)s.insert(a[v]);
    }
}



void solve(){
    cin>>n;
    for(int i = 1;i <= n;i ++){//初始化
        g[i].clear();
        f[i] = sum[i] = 0;
    }
    for(int i = 1;i <= n;i ++)cin>>a[i];//晶蝶数量
    for(int i = 1;i <= n;i ++)cin>>t[i];//晶蝶消失的时间
    for(int i = 1;i <= n-1;i ++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<f[1] + a[1]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}