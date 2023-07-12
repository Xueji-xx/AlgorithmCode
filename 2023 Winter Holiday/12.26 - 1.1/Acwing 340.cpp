#include <iostream>
#include <deque>
#include <vector>
#include <string.h>
using namespace std;
const int N = 2e4+50;
int h[N],e[N],w[N],ne[N],cnt;
bool vis[N];
int dis[N];
int n,m,k;

void add(int a,int b,int c){
    e[cnt] = b;
    w[cnt] = c;
    ne[cnt] = h[a];
    h[a] = cnt++;
}

int check(int mid){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    deque<int> q;
    q.push_back(1);
    dis[1] = 0;
    while(q.size()){
        auto t = q.front();
        q.pop_front();
        if(vis[t])continue;
        vis[t] = 1;
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            int x = w[i] > mid;
            if(dis[j] > dis[t] + x){
                dis[j] = dis[t] + x;
                if(!x)q.push_front(j);
                else q.push_back(j);
            }
        }
    }
    return dis[n] <= k;
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m>>k;
    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c);
        add(v,u,c);
    }
    int l = 0,r = 1e6+50;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    if(r == 1e6+50)cout<<-1<<endl;
    else cout<<r<<endl;
    return 0;
}