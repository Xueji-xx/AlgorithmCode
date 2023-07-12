#include <iostream>
#include <set>
#include <string.h>
using namespace std;

const int N = 2e5+50;
const int M = N * 2;
int n;
set<int> s[N];
int in[N];
int e[M],ne[M],h[N],cnt;
bool vis[N];

bool dfs(int u){
    vis[u] = true;
    bool flag = in[u] == 2;
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(vis[j])continue;
        flag &= dfs(j);
    }
    return flag;
}


void add(int u,int v){
    e[cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt ++;
}

void solve(){
    cin >> n;
    cnt = 0;
    memset(in, 0, sizeof in);
    memset(vis, 0, sizeof vis);
    memset(h, -1, sizeof h);
    for(int i = 1;i <= n;i ++)s[i].clear();
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        if(!s[i].count(x)){
            s[x].insert(i);
            s[i].insert(x);
            in[x] ++;
            in[i] ++;
            add(i,x);
            add(x,i);
        }
    }
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            if(dfs(i))cnt1 ++;
            else cnt2 ++;
        }
    }
    cout << cnt1 + (cnt2 > 0) << ' ' << cnt1 + cnt2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}