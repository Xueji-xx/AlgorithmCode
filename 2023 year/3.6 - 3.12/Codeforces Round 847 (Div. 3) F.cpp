#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5+50;
int c[N];
vector<int> g[N];
int fa[N],maxm[N];


void dfs(int u){
    for(auto j : g[u]){
        if(j == fa[u])continue;
        fa[j] = u;
        dfs(j);
    }
}

void solve(){
    int n;
    cin>>n>>c[1];
    for(int i = 2;i <= n;i ++)cin>>c[i];
    for(int i = 1;i <= n;i ++){
        g[i].clear();
        maxm[i] = n+1;
    }
    for(int i = 1;i < n;i ++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int ans = n+1;
    for(int i = 1;i <= n;i ++){
        int t = c[i];
        int res = 0;
        while(t && res < ans){
            ans = min(ans,res + maxm[t]);
            maxm[t] = min(maxm[t],res);
            t = fa[t];
            res++;
        }
        if(i != 1)cout<<ans<<" \n"[i == n];
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}