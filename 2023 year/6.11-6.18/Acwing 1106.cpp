#include <iostream>
#include <queue>
using namespace std;

int map[1050][1050];
typedef pair<int,int> PII;
bool vis[1050][1050];
int n;

int dx[] = {-1,-1,-1,0,1,1,1,0},dy[] = {-1,0,1,1,1,0,-1,-1};

int bfs(int x,int y){
    bool high = false;
    bool low = false;
    queue<PII> q;
    q.push({x,y});
    vis[x][y] = true;
    while(q.size()){
        auto t = q.front();
        q.pop();
        for(int i = 0;i < 8;i ++){
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if(xx <= 0 || xx > n ||yy <= 0 || yy > n)continue;
            if(map[xx][yy] != map[t.first][t.second]){
                if(map[xx][yy] > map[t.first][t.second])high = true;
                if(map[xx][yy] < map[t.first][t.second])low = true;
            }
            else if(!vis[xx][yy]){
                vis[xx][yy] = true;
                q.push({xx,yy});
            }
            
        }
    }
    if(high && low) return -1;
    else if(!high &&!low) return 0;
    else if(!high) return 1;
    else return 2;
}

int main(){

    cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cin >> map[i][j];
        }
    }
    int peek = 0;
    int valley = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(!vis[i][j]){
                int t = bfs(i,j);
                if(t == 0)peek ++,valley ++;
                if(t == 1)peek ++;
                if(t == 2)valley ++;
            }
        }
    }
    cout << peek << ' ' << valley << endl;
    return 0;
}