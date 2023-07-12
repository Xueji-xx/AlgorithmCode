#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 1e5+50;

vector<pair<int,int>> tr[N];
int n,a,b;
set<int> s;

void dfs1(int u,int fa,int x){
    if(u == b)return;
    s.insert(x);
    for(auto i : tr[u]){
        int v = i.first,w = i.second;
        if(v == fa)continue;
        dfs1(v,u,x ^ w);
    }
}

bool dfs2(int u,int fa,int x){
    if(u != b && s.count(x))return true;
    for(auto i : tr[u]){
        int v = i.first,w = i.second;
        if(v == fa)continue;
        if(dfs2(v,u,x ^ w))return true;
    }
    return false;
}

void solve(){
    s.clear();
    cin>>n>>a>>b;
    for(int i = 0;i < n;i ++)tr[i].clear();
    a --,b --;
    for(int i = 0;i < n-1;i ++){
        int u,v,w;
        cin>>u>>v>>w;
        u --,v --;
        tr[u].push_back({v,w});
        tr[v].push_back({u,w});
    }
    dfs1(a,-1,0);
    if(dfs2(b,-1,0))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}