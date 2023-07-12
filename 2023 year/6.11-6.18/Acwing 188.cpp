#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int N = 200;
char map[N][N];
int sx,sy,fx,fy;
int n,m;
int dis[N][N];
const int dx[8]= {1,2,2, 1,-1,-2,-2,-1};
const int dy[8]= {2,1,-1,-2,-2,-1,1,2};

typedef pair<int,int> PII;


int bfs(){
    memset(dis,-1,sizeof dis);
    queue<PII> q;
    q.push({sx,sy});
    dis[sx][sy] = 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i = 0;i <= 7;i ++){
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if(xx > 0 && xx <= n && yy > 0 && yy <= m  && map[xx][yy] != '*' && dis[xx][yy] == -1){
                dis[xx][yy] = dis[t.first][t.second] + 1;
                q.push({xx,yy});
                if(xx == fx && yy == fy){
                    return dis[xx][yy];
                }
            }
        }
    }   
    return -1;
}

int main(){
    cin >> m >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> map[i][j];
            if(map[i][j] == 'K'){
                sx = i;
                sy = j;
            }
            if(map[i][j] == 'H'){
                fx = i;
                fy = j;
            }
        }
    }
    cout << bfs();
    return 0;
}