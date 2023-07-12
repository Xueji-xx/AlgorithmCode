#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int N = 5e5+50;
const int M = 2147483647;

struct edge{
    int w;
    int to;
    int next;
}e[N];
int cnt = 0;
int n,m,s;
int head[N];
bool vis[N];
long long dis[N];
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII>>h;
void add(int u,int v,int w){
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra(){
    for(int i = 1;i <= n;i ++){
        dis[i] = M;
    }
    dis[s] = 0;
    
    h.push({0,s});
    while(h.size()){
        int u = h.top().second;
        h.pop();
        if(vis[u])continue;
        vis[u] = true;
        for(int i = head[u];i;i = e[i].next){
            int v = e[i].to,w = e[i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                h.push(make_pair(dis[v],v));
            }
        }
    }
}


int main(){
    cin>>n>>m>>s;
    memset(head,-1,sizeof head);
    for(int i = 0;i < m;i ++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra();
    for(int i = 1;i <= n;i ++){
        cout<<dis[i]<<' ';
    }
    system("pause");
    return 0;
}