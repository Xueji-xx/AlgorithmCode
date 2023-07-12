#include<iostream>
#include<string.h>
using namespace std;
const int N = 550, M = 1e5+50;

int n,m,k;
struct edge
{
    int a,b,w;
}e[M];
int dis[N];
int vis[N];


int bellman_ford(){
    memset(dis,0x3f3f3f3f,sizeof dis);
    dis[1] = 0;
    for(int i = 0;i < k;i ++){
        memcpy(vis,dis,sizeof dis);
        for(int j = 0;j < m;j ++){
            int a = e[j].a,b = e[j].b,w = e[j].w;
            dis[b] = min(dis[b],vis[a] + w);
        }
    }
    if(dis[n] == 0x3f3f3f3f)return -1;
    else return dis[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i = 0;i < m;i ++){
        int a,b,w;
        cin>>a>>b>>w;
        e[i] = {a,b,w};
    }
    int res = bellman_ford();
    if(res == -1)cout<<"impossible"<<endl;
    else cout<<res<<endl;
    return 0;
}