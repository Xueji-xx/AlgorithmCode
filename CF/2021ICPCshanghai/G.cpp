#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int N = 1e6+50;
const int MOD = 998244353;
vector<int> tr[N];
int f[N];

int dfs(int u,int fa){
    f[u] = 1;
    int res = 0;
    for(auto v:tr[u]){
        if(v == fa)continue;
        if(!dfs(v,u)){
            res++;
        }
        f[u] = f[u] * f[v] % MOD;
    }
    for(int i = 1;i <= res;i += 2){
        f[u] = f[u] * i % MOD;
    }
    return res & 1;
}

signed main(){
    int n;
    cin>>n;
    for(int i = 0;i < n-1;i ++){
        int a,b;
        cin>>a>>b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    dfs(1,0);
    cout<<f[1]<<endl;
    return 0;
}