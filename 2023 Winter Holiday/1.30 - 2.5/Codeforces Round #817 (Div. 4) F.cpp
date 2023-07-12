#include <iostream>
#include <string.h>
using namespace std;
const int N = 55;
char a[N][N];
bool vis[N][N];
int dx[]={1,-1,0,0,-1,-1,1,1},dy[]={0,0,1,-1,-1,1,-1,1};
int n,m;
int cnt;
int change[10];

void dfs(int x,int y,bool f){
    vis[x][y] = true;
    cnt++;
    if(cnt > 3)return; 
    for(int i = 0;i < (f?8:4);i ++){
        int xx = x + dx[i],yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] == '.' || vis[xx][yy])continue;
        if(!f)change[cnt] = i;
        dfs(xx,yy,f);
        if(cnt > 3)return;
    }
}


void solve(){
    bool flag = true;
    memset(vis,false,sizeof vis);
    cin>>n>>m;
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(a[i][j] == '*' && !vis[i][j]){
                cnt = 0;
                dfs(i,j,0);
                if(cnt != 3 || change[1] == change[2]){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag)break;
    }
    if(!flag){
        cout<<"NO"<<endl;
        return;
    }
    memset(vis,false,sizeof vis);
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            if(a[i][j] == '*' && !vis[i][j]){
                cnt = 0;
                dfs(i,j,1);
                if(cnt != 3){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag)break;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}