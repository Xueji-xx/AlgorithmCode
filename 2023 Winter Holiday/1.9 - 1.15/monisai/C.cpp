#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+50;

vector<int> tree[N];
int d[N];
bool vis[N];

void dfs(int u){
    bool flag = false;
    vis[u] = true;
    for(int i = 0;i < tree[u].size();i ++){
        int v = tree[u][i];
        if(vis[v])continue;
        flag = true;
        dfs(v);
        d[u] = max(d[u],d[v] + 1);
    }
    if(!flag){
        d[u] = 1;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 1;i < n;i ++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    int ans = 0;
    for(int i = 0;i < tree[1].size();i ++){
        ans += d[tree[1][i]];
    }
    cout<<ans<<endl;
    return 0;
}