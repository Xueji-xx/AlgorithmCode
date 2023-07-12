#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int N = 150;
const int M = 10110;
int n,k;
int lev[N],dis[N];
bool vis[N];
int h[N],e[M],w[M],ne[M],cnt;
typedef pair<int,int> PII;

void add(int u,int v,int val){
    e[cnt] = v;
    w[cnt] = val;
    ne[cnt] = h[u];
    h[u] = cnt++;
}

int dijkstra(int l,int r)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);

    priority_queue<PII,vector<PII>,greater<PII>> heap;

    dis[0]=0;
    heap.push({0,0});
    while(heap.size())
    {
        PII t=heap.top();
        heap.pop();

        int u=t.second;
        if(vis[u])continue;
        vis[u]=true;

        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(lev[j]>r||lev[j]<l)
                continue;
            if(dis[j]>dis[u]+w[i])
            {
                dis[j]=dis[u]+w[i];
                heap.push({dis[j],j});
            }
        }
    }

    return dis[1];
}

int main(){
    cin>>k>>n;
    memset(h,-1,sizeof h);
    for(int i = 1;i <= n;i ++){
        int p,l,m;
        cin>>p>>l>>m;
        add(0,i,p);
        lev[i] = l;
        for(int j = 0;j < m;j ++){
            int u,v;
            cin>>u>>v;
            add(u,i,v);
        }
    }
    int res = 1e9;
    for(int i = lev[1] - k;i <= lev[1];i ++)res = min (res, dijkstra(i,i+k));
    cout<<res<<endl;
    return 0;
}
