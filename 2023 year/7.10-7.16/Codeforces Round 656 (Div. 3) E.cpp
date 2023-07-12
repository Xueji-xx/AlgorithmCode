#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

const int N = 2e5+50;
int u[N],v[N];
vector<int> h[N];
int cnt[N],k;
queue<int> q;
int vis[N];
int n,m;

void topsort(){
    for(int i = 1;i <= n;i ++){
        if(!vis[i])q.push(i);
    }
    while(q.size()){
        int u = q.front();
        q.pop();
        cnt[u] = ++k;
        for(auto i : h[u]){
            vis[i] --;
            if(!vis[i])q.push(i);
        }
    }
}

void solve(){
    memset(cnt,0,sizeof cnt);
    memset(vis,0,sizeof vis);
    k = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)h[i].clear();
    for(int i = 1;i <= m;i ++){
        int flag;
        cin >> flag >> u[i] >> v[i];
        if(flag){
            vis[v[i]] ++;
            h[u[i]].push_back(v[i]);
        }
    }
    topsort();
    if(k < n)cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 1;i <= m;i ++){
            if(cnt[u[i]] < cnt[v[i]])cout << u[i] << ' ' << v[i] << endl;
            else cout << v[i] << ' ' << u[i] << endl;
        }
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}