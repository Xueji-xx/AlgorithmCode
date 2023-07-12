#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int N = 1e5+50;
int e[N],ne[N],h[N],cnt;
int d[N];
int q[N];
int n,m;

void add(int u,int v){
    e[++cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt;
}

bool topsort(){
    int hh = 0,tt = -1;
    for(int i = 1;i <= n;i ++){
        if(!d[i]){
            q[++tt] = i;
        }
    }
    while(hh <= tt){
        int t = q[hh ++];
        for(int i = h[t]; i ;i = ne[i]){
            int j = e[i];
            if(!--d[j])q[++tt] = j;
        }
    }
    return tt == n-1;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int a,b;
        cin >> a >> b;
        add(b,a);
        d[a] ++;
    }
    if(!topsort()){
        cout << "Poor Xed" << endl;
    }
    else{
        int dis[N];
        for(int i = 1;i <= n;i ++){
            dis[i] = 100;
        }
        for(int i = 0;i < n;i ++){
            int nxd = dis[q[i]] + 1;
            for(int j = h[q[i]];j;j = ne[j]){
                dis[e[j]] = max(dis[e[j]],nxd);
            }
        }
        int sum = 0;
        for(int i = 1;i <= n;i ++){
            sum += dis[i];
        }
        cout << sum << endl;
    }
    return 0;
}