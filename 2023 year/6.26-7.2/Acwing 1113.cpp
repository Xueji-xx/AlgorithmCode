#include <iostream>
#include <string.h>
using namespace std;

int ans = 0;
char map[25][25];
bool vis[25][25];
int mov[] = {0,1,0,-1,0};
int w,h;
void dfs(int x,int y){
    if(x < 1 || x > w || y < 1 || y > w || map[x][y] == '#')return;
    if(map[x][y] == '.')ans ++;
    map[x][y] = '#';
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
}


int main(){
    while(cin >> w >> h && (w || h)){
        ans = 0;
        int sx,sy;
        for(int i = 1;i <= w;i ++){
            for(int j = 1;j <= h;j ++){
                cin >> map[i][j];
                if(map[i][j] == '@'){
                    sx = i,sy = j;
                }
            }
        }
        dfs(sx,sy);
        cout << ans + 1<< endl;
    }
    return 0;
}