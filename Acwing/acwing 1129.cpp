#include<iostream>
#include<string.h>
#include<queue>
#define x first
#define y second
using namespace std;
int n,m,s,t;

const int N = 3000,M = 6500<<1;
typedef pair<int,int> PII;
struct Edge{
    int u,v,w;
}e[M];
int head[N],idx;
int dis[N];
bool vis[N];

void add(int a,int b,int c){
    e[idx].v = b;
    e[idx].w = c;
    e[idx].u = head[a];
    head[a] = idx++;
}

void dijkstra(){
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    priority_queue<PII,vector<PII>,greater<PII>> h;
    h.push({0,s});
    dis[s] = 0;
    while(h.size()){
        PII t = h.top();
        h.pop();
        vis[t.y] = true;
        for(int i = head[t.y] ;i != -1;i = e[i].u){
            int j = e[i].u;
            if(dis[j] > dis[t.y] + e[i].w){
                dis[j] = dis[t.y] + e[i].w;
                h.push({dis[j],j});
            }
        }
    }
}


int main(){
    memset(head,-1,sizeof head);
    cin>>n>>m>>s>>t;
    while(m --){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dijkstra();
    cout<<dis[t]<<endl;
    return 0;
}