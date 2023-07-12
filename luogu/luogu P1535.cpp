#include<iostream>
#include<math.h>
using namespace std;
int n,m,t;
int sx,sy,fx,fy;
char map[200][200];
int ans = 0;
int mov[] = {0,1,0,-1,0};
void dfs(int x,int y,int cnt){
    if(x == fx && y == fy && !cnt){
        ans+=1;
        return;
    }
    if(abs(x-fx) + abs(y-fy) > cnt )return;
    for(int i = 0;i < 4;i ++){
        int xx = x + mov[i],yy = y + mov[i+1];
        if(xx > 0 && xx <= n && yy > 0 && yy <= m && map[xx][yy] != '*'){
            dfs(xx,yy,cnt-1);
        }
    }
}


int main(){
    cin>>n>>m>>t;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin>>map[i][j];
        }
    }
    cin>>sx>>sy>>fx>>fy;
    dfs(sx,sy,t);
    cout<<ans<<endl;
    return 0;
}