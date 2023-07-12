#include<iostream>
using namespace std;
const int N = 1050;

char map[N][N];
int dx[8]={1,0,-1,0,1,-1,1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};

void dfs(int x,int y){
    map[x][y] = '.';
    for(int i = 0;i < 8;i ++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(map[xx][yy] == 'W')dfs(xx,yy);
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin>>map[i][j];
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(map[i][j] == 'W'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}