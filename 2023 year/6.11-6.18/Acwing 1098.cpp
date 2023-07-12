#include <iostream>
#include <queue>
using namespace std;

const int N = 100;

int m,n;
int map[N][N];
bool vis[N][N];
int mov[] = {0,-1,0,1,0};

typedef pair<int,int> PII;

int bfs(int x,int y){
    int res = 0;
    vis[x][y] = true;

    queue<PII> q;
    q.push({x,y});
    while(q.size()){
        auto t = q.front();
        q.pop();
        res ++;
        for(int i = 0;i < 4;i ++){
            if(map[t.first][t.second] >> i & 1)continue;
            int xx = t.first + mov[i];
            int yy = t.second + mov[i+1];
            if(xx <= 0 || xx > m || yy <= 0 || yy > n)continue;
            if(vis[xx][yy])continue;
            vis[xx][yy] = true;
            q.push({xx,yy});
        }
    }
    return res;
}

int main(){
    cin >> m >> n;
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            cin >> map[i][j];
        }
    }
    int ans = 0,num = 0;
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= n;j ++){
            if(!vis[i][j]){
                num ++;
                int t = bfs(i,j);
                ans = max(ans,t);
            }
        }
    }
    cout << num << endl << ans << endl;
    return 0;
}