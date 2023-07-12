#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
int n,m;
const int N = 1e6+50;
vector<int> g[N];
bool vis[N];
int dis[N],ans[N];


void spfa(int x){
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    q.push(x);
    vis[x] = true;
    ans[x] = 1;
    dis[x] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i = 0;i < g[u].size();i ++){
            int v = g[u][i];
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                ans[v] = ans[u];
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
            else if(dis[v] == dis[u] + 1){
                ans[v] = (ans[v] + ans[u])%100003;
            }
        }
    }
}


int main(){
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    spfa(1);
    for(int i = 1;i <= n;i ++)cout<<ans[i]<<endl;
    system("pause");
    return 0;
}