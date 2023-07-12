#include<iostream>
#include<climits>
#include<string.h>
#include<queue>
using namespace std;
#define int long long
const int N = 5000;

int e[N],w[N],ne[N],idx;
int head[N];
int dis[N];
bool vis[N];
int num[N];
int c,n,m;

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = head[a];
    head[a] = idx++;
}

int dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[s] = 0;
    vis[s] = true;
    priority_queue<pair<int,int>> q;
    q.push({0,s});
    while(q.size()){
        int x = q.top().second;
        q.pop();
        if(vis[x])continue;
        vis[x] = true;
        for(int i = head[x];~i;i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[x] + w[i]){
                dis[j] = dis[x] + w[i];
                q.push({-dis[j],j});
            }
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i ++){
        res += num[i] * dis[i];
    }
    return res;
}

signed main(){
    memset(head,-1,sizeof head);
    cin>>c>>n>>m;
    while(c--){
        int x;
        cin>>x;
        num[x]++;
    }
    int ans = LONG_LONG_MAX;
    while(m --){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    for(int i = 1;i <= n;i ++)ans = min(ans,dijkstra(i));
    cout<<ans<<endl;
    return 0;
}