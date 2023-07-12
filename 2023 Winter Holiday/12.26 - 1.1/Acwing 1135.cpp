#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 5e5+50;
const int M = 2e5+50;
int n,m;
int h[N],e[M],ne[M],cnt,w[M],source[6],dis[6][M];
bool vis[N];

void add(int a,int v,int c){
    e[cnt] = v;
    w[cnt] = c;
    ne[cnt] = h[a];
    h[a] = cnt++;
}

void dijkstra(int l,int dis[]){
    memset(dis,0x3f,N*4);
    dis[l] = 0;
    memset(vis,0,sizeof vis);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,l});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int v = t.second;
        if(vis[v])continue;
        vis[v] = true;
        for(int i = h[v];~i;i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[v] + w[i]){
                dis[j] = dis[v] + w[i];
                heap.push({dis[j],j});
            }
        }
    }
}

int dfs(int u,int start,int s){
    if(u > 5)return s;
    int res = 0x3f3f3f3f;
    for(int i = 1;i <= 5;i ++){
        if(!vis[i]){
            int to = source[i];
            vis[i] = true;
            res = min(res,dfs(u+1,i,s + dis[start][to]));
            vis[i] = false;
        }
    }
    return res;
}

int main(){
    cin>>n>>m;
    source[0] = 1;
    for(int i = 1;i <= 5;i ++)cin>>source[i];
    memset(h,-1,sizeof h);
    while(m --){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    for(int i = 0;i <= 5;i ++){
        dijkstra(source[i],dis[i]);
    }
    memset(vis,0,sizeof vis);
    cout<<dfs(1,0,0)<<endl;
    return 0;
}