//1900
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int N = 2e5+50;
int a[N],f[2][N];
vector<int> tr[N],p;

void dfs(int u,int fa,int d){
    p.push_back(u);
    a[u] = 1;
    if(p.size() > d)a[u] = p[p.size() -1 -d];
    for(auto v:tr[u]){
        if(v == fa)continue;
        dfs(v,u,d);
    }
    p.pop_back();
}

void dfs2(int u,int fa,int chess){
    bool flag = false;
    for(auto v : tr[u]){
        if(v == fa)continue;
        dfs2(v,u,chess);
        flag |= f[chess][v];
    }
    f[chess][u] |= flag;
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i < n;i ++){
        int x,y;
        cin>>x>>y;
        tr[x].push_back(y);
        tr[y].push_back(x);
    }
    dfs(1,0,k);
    for(int i = 0;i <= 1;i ++){
        int m;
        cin>>m;
        for(int j = 1;j <= m;j ++){
            int x;
            cin>>x;
            f[i][x] = f[i ^ 1][a[x]] = 1;
        }
    }
    dfs2(1,0,0);
    dfs2(1,0,1);

    int res = 0;
    for(int i = 0;i <= 1;i ++){
        res += accumulate(&f[i][2],&f[i][n+1],0);
    }
    cout<<res*2<<endl;
    return 0;
}