#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

#define x first
#define y second

int head[600],e[600],ne[600],w[600],idx;
int dis[600];
bool vis[600];
int n,m;

typedef pair<int,int> PII;

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = head[a];
    head[a] = idx++;
}

int dijkstra(){
    int res = 0,cnt = 0;
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> h;
    h.push({0,1});
    while(h.size()){
        PII u = h.top();
        h.pop();
        if(vis[u.y])continue;
        vis[u.y] = true;
        res = max(res,u.x);
        cnt ++;
        for(auto i = head[u.y];i != -1;i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[u.y] + w[i]){
                dis[j] = dis[u.y] + w[i];
                h.push({dis[j],j});
            }
        }
    }
    cout<<(cnt == n ? res : -1);
}

int main(){
    memset(head,-1,sizeof head);
    cin>>n>>m;
    while(m --){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dijkstra();
    return 0;
}