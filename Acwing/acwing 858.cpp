#include<iostream>
#include<string.h>
using namespace std;
const int N = 550;
const int INF = 0x3f3f3f3f;
int map[N][N];
int dis[N];
bool vis[N];
int n,m;

int prim(){
    memset(dis,0x3f,sizeof dis);
    int res = 0;
    for(int i = 0;i < n;i ++){
        int t = -1;
        for(int j = 1;j <= n;j ++){
            if(!vis[j] && (t == -1 || dis[t] > dis[j])){
                t = j;
            }
        }
        if(i && dis[t] == INF)return INF;
        if(i)res += dis[t];
        vis[t] = true;
        for(int j = 1;j <= n;j ++){
            dis[j] = min(dis[j],map[t][j]);
        }
    }
    return res;
}


int main(){
    memset(map,0x3f,sizeof map);
    cin>>n>>m;
    for(int i = 1;i <= m;i ++){
        int a,b,v;
        cin>>a>>b>>v;
        map[a][b] = map[b][a] = min(v,map[a][b]);
    }
    int t = prim();
    if(t == INF)cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}