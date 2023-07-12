#include <iostream>
#include <string.h>
using namespace std;
#define int long long

int dis[150][150];

signed main(){
    int n,m,sp,tp,t;
    cin>>n>>m>>sp>>tp>>t;
    memset(dis,0x3f,sizeof dis);
    for(int i = 0;i < m;i ++){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = dis[v][u] = w;
    }
    for(int k = 1;k <= n;k ++){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    if(dis[sp][tp] > t)cout<<'B';
    else cout<<'A';
    return 0;
}