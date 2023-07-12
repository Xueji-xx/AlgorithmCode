#include <iostream>
#include <string.h>

using namespace std;
const int N = 5000010;
int n,m,s;
struct node{
    int u,v,nex;
}e[N << 1];
int head[N];
int cnt;

void add(int u,int v){
    e[++cnt].v = v;
    e[cnt].u = u;
    e[cnt].nex = head[u];
    head[u] = cnt;
}

int depth[N],fa[N][30],lg[N],x,y;

void dfs(int now,int fath){
    fa[now][0] = fath;
    depth[now] = depth[fath] + 1;
    for(int i = 1;i <= lg[depth[fath]] - 1;i ++){
        fa[now][i] = fa[fa[now][i-1]][i-1];
    }
    for(int i = head[now];i;i = e[i].nex){
        if(e[i].v != fath){
            dfs(e[i].v,now);
        }
    }
}

int LCA(int x,int y){
    if(depth[x] < depth[y]){
        swap(x,y);
    }
    while(depth[x] > depth[y]){
        x = fa[x][lg[depth[x] - depth[y]] - 1];
    }
    if(x == y)return x;
    for(int i = lg[depth[x]] - 1;i >= 0;i --){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i],y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    cin >> n >> m >> s;
    for(int i = 1;i <= n-1;i ++){
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    for(int i = 1;i <= n;i ++){
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    }
    dfs(s,0);
    for(int i = 1;i <= m;i ++){
        cin >> x >> y;
        cout << LCA(x,y) << endl;
    }
    return 0;
}