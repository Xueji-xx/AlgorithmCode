#include <iostream>
#include <string.h>
using namespace std;
#define int long long
const int N = 1e6+10;

int h[N],v[N],nxt[N],w[N],tot;
bool vis[N];
int cnt[40][5];
int val[N];
bool flag = false;

void add(int a,int b,int c){
    v[++tot] = b;
    w[tot] = c;
    nxt[tot] = h[a];
    h[a] = tot;
}

void dfs(int x,int fa = 0){
    if(!flag)return;
    vis[x] = true;
    for(int i = 30;i >= 0;i --){
        cnt[i][val[x] >> i & 1]++;
    }
    for(int i = h[x];i;i = nxt[i]){
        int y = v[i];
        if(vis[y]){
            if((val[y] ^ val[x]) != w[i]){
                flag = false;   
                return;
            }
        }
        else{
            val[y] = val[x] ^ w[i];
            dfs(y,x);
        }
    }
}

signed main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < m;i ++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    flag = true;
    int res = 0;
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            memset(cnt,0,sizeof cnt);
            dfs(i);
            for(int j = 30;j >= 0;j --){
                res += min(cnt[j][0],cnt[j][1])*(1 << j);
            }
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;
}