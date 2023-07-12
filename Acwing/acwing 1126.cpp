#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n,m,a,b;
int s,t;
const int N = 2050,M = 2e5+50;
int head[N],e[M],ne[M],idx;
double dis[N],w[M];
bool vis[N];
typedef pair<double,int> PII;

void add(int a,int b,int c){
    e[++idx] = b;
    w[idx] = 1 - c*0.01;
    ne[idx] = head[a];
    head[a] = idx;
}

void dijkstra(){
    memset(dis,0x7f,sizeof dis);
    priority_queue<PII,vector<PII>,greater<PII>>h;
    h.push({100,t});
    dis[t] = 100;   
    while(h.size()){
        int x = h.top().second;
        h.pop();
        if(vis[x])continue;
        vis[x] = true;
        for(int i = head[x];i;i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[x] / w[i]){
                dis[j] = dis[x] / w[i];
                h.push({dis[j],j});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    while(m --){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    cin>>s>>t;
    dijkstra();
    printf("%.8lf",dis[s]);
    return 0;
}