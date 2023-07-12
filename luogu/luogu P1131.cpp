#include <iostream>
using namespace std;
const int N = 500500;
struct Edge{
    int ne;
    int to;
    int w;
}e[N];
int n,s,cnt,head[N],maxm[N];
long long ans;

void add(int a,int b,int c){
    e[++cnt].to = b;
    e[cnt].w = c;
    e[cnt].ne = head[a];
    head[a] = cnt;
}

void dfs(int u,int fa){
    for(int i = head[u];i;i = e[i].ne){
        if(e[i].to != fa){
            dfs(e[i].to,u);
        }
    }
    for(int i = head[u];i;i = e[i].ne){
        if(e[i].to != fa){
            maxm[u] = max(maxm[u],e[i].w);
        }
    }
    for(int i = head[u];i;i = e[i].ne){
        if(e[i].to != fa){
            ans += (maxm[u] - e[i].w);
        }
    }
    for(int i = head[fa];i;i = e[i].ne){
        if(e[i].to == u){
            e[i].w += maxm[u];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>s;
    for(int i = 1;i <= n-1;i ++){
        int a,b,t;
        cin>>a>>b>>t;
        add(a,b,t);
        add(b,a,t);
    }
    dfs(s,0);
    cout<<ans<<endl;
    return 0;
}