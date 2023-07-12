#include <iostream>
using namespace std;
int n,m,k;
char map[550][550];
bool vis[550][550];

void dfs(int x,int y){
    if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] != '.' || vis[x][y]){
        return;
    }
    vis[x][y] = true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    if(k){
        map[x][y] = 'X';
        k--;
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i = 0;i < n;i ++){
        cin>>map[i];
    }
    for(int i = 0;i < n && k;i ++){
        for(int j = 0;j < m && k;j ++){
            dfs(i,j);
        }
    }
    for(int i = 0;i < n;i ++)cout<<map[i]<<endl;
    return 0;
}