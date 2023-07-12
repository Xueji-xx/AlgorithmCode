#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
const int N = 1e5+50;
int e[2*N],ne[2*N],w[2*N],h[2*N],cnt;
long long dis[N];
int pre[N],res[N];
bool vis[N];
typedef pair<int,int> PII;

void add(int a,int b,int c){
    e[cnt] = b;
    w[cnt] = c;
    ne[cnt] = h[a];
    h[a] = cnt ++;
}

int dijkstra(){
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dis,-1,sizeof dis);
    dis[1] = 0;
    q.push({0,1});
    while(q.size()){
        auto t = q.top();
        q.pop();
        int ver = t.second,dist = t.first;
        if(vis[ver])continue;
        vis[ver] = true;
        for(int i = h[ver];~i;i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[ver] + w[i] || dis[j] == -1){
                dis[j] = dis[ver] + w[i];
                q.push({dis[j],j});
                pre[j] = ver;
            }
        }
    }
    return dis[n];
}

int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m --){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    int t = dijkstra();
    if(t == -1){
        cout << -1 << endl;
        return 0;
    }
    int now = n,idx = 0;
    while(now != 1){
        res[idx ++] = now;
        now = pre[now];
    }
    res[idx++] = 1;
    for(int i = idx-1;i >= 0;i --){
        cout << res[i] << ' ';
    }
    return 0;
}