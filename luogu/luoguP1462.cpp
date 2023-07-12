#include<iostream>
#include<string.h>
#include<queue>
const int N = 1e5;
const int M = 1000000005;
using namespace std;
int fy[N],dis[N],head[N];
bool vis[N];
int n,m,b,cnt;

struct edge{
    int to,next,w;
}e[N];

void add(int u,int v,int w){
    e[++cnt].w = w;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool dijkstra(int x){
    if(x < fy[1])return false;
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push({0,1});
    int a;
    while(q.size()){
        a = q.top().second;
        q.pop();
        if(vis[a])continue;
        vis[a] = true;
        for(int i = head[a];i;i = e[i].next){
            if(fy[e[i].to] <= x && vis[e[i].to] == false && dis[e[i].to] > dis[a] + e[i].w){
                dis[e[i].to] = dis[a] + e[i].w;
                q.push({dis[e[i].to],e[i].to});
            }
        }
    }
    if(dis[n] < b)return true;
    return false;
}



int main(){
    cin>>n>>m>>b;
    for(int i = 1;i <= n;i ++){
        cin>>fy[i];
    }
    for(int i = 0;i < m;i ++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    if(!dijkstra(M)){
        cout<<"AFK"<<endl;
        return 0;
    }
    int l = 1,r = M,mid = (l+r)>>1;
    bool c;
    while(l <= r){
        c = dijkstra(mid);
        if(c){
            r = mid - 1;
            mid = (l+r)>>1;
        }
        else{
            l = mid + 1;
            mid = (l+r)>>1;
        }
    }
    cout<<l<<endl;
    system("pause");
}