#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long 

const int N = 2e5+50;
int d[N];
int fa[N];
int val[N];
int s[N];
vector<int> g[N];

void dfs(int x,int deep){
    val[x] = deep;
    s[x] = 1;
    for(auto i:g[x]){
        if(fa[x] != i){
            s[x] += s[i];
            fa[i] = x;
            dfs(i,deep + 1);
            s[x] += s[i];
            val[x] -= s[i];
        }
    }
}


signed main(){
    int n,k;
    cin>>n>>k;
    int x,y;
    for(int i = 1;i < n;i ++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    d[1] = 0;
    fa[1] = 1;
    dfs(1,0);
    sort(val+1,val+1+n);
    int ans = 0;
    for(int i = n;i >= n - k + 1;i --){
        ans += val[i];
    }
    cout<<ans<<endl;
    return 0;
}