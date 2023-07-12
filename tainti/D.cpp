#include <iostream>
using namespace std;
int n;
bool vis[1030];
int dis[1030][1030];

void dfs(int p){
    vis[p] = true;
    for(int i = 1;i <= n;i ++){
        if(dis[p][i] == 1 && !vis[i])dfs(i);
    } 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int m;
    cin>>m;
    while(m --){
        char op;
        cin>>op;
        int a,b;
        cin>>a>>b;
        if(op == 'E'){
            dis[a][b] = dis[b][a] = -1;
            for(int i = 1;i <= n;i ++){
                if(dis[a][i] == -1)dis[b][i] = dis[i][b] = 1;
                if(dis[b][i] == -1)dis[a][i] = dis[i][a] = 1;
            }
        }
        else if(op == 'F'){
            dis[a][b] = dis[b][a] = 1;
            /*for(int i = 1;i <= n;i ++){
                if(dis[a][i] == 1)dis[b][i] = dis[i][b] = 1;
                if(dis[b][i] == 1)dis[a][i] = dis[i][a] = 1;
            }*/
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
