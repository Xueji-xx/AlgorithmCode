#include<iostream>
using namespace std;
char map[550][550];
bool vis[550][550];
int res;
int mov[] = {0,1,0,-1,0};
int n,m;
int ans, nex;
void dfs(int x,int y){
    vis[x][y] = true;
    if(map[x][y] == '*')res++;
    for(int i = 0;i < 4;i ++){
        int xx = x + mov[i],yy = y + mov[i+1];
        if(xx > 0 && xx <= n && yy > 0 && yy <= m && !vis[xx][yy] && map[xx][yy] != '#'){
            dfs(xx,yy);
        }
    }
}



int main(){
	cin>>n>>m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin>>map[i][j];
        }
    }
    
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(map[i][j] == '*' && !vis[i][j]){
                res = 0;
                dfs(i,j);
                if(ans < res){
                    nex = ans;
                    ans = res;
                }
                else if(res > nex){
                    nex = res;
                }
            }
        }
    }
    cout<<ans+nex;
    return 0;
}
