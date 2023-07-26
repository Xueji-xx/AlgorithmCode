#include <iostream>
#include <vector>
using namespace std;

#define int long long
const int N = 1e6+50;

bool flag;
int n,m;
vector<vector<int>> e(N);
bool vis[N];
int dis[N];

void dfs(int k){
    if(!flag)return;
    vis[k] = 1;
    for(auto i : e[k]){
        if(vis[i])continue;
        if(!dis[i]){
            dis[i] = dis[k] + 1;
        }
        else if(dis[i] != dis[k] + 1)flag = false;
        dfs(i);
    }
    vis[k] = 0;
}


void Elysia(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        e[i].clear();
        vis[i] = dis[i] = 0;
    }
    for(int i = 1;i <= m;i ++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    flag = true;
    dfs(1);
    if(flag)cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t --){
        Elysia();
    }
    return 0;
}