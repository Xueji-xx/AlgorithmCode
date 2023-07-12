#include <iostream>
#include <queue>
using namespace std;
#define x first
#define y second
int n;
const int N = 1050;
int map[N][N];
typedef pair<int,int> PII;
int mov[] = {0,1,0,-1,0};
bool vis[N][N];
PII pre[N][N];

void bfs(){
    queue<PII> q;
    q.push({n-1,n-1});
    vis[n-1][n-1] = true;
    while(q.size()){
        PII a = q.front();
        q.pop();
        for(int i = 0;i < 4;i ++){
            int xx = a.x + mov[i];
            int yy = a.y + mov[i+1];
            if(!vis[xx][yy] && xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy] == 0){
                q.push({xx,yy});
                vis[xx][yy] = true;
                pre[xx][yy] = a;
            }
        }
    }
}


int main(){
    cin>>n;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < n;j ++){
            cin>>map[i][j];
        }
    }
    bfs();
    PII end = {0,0};
    cout<<0 <<' '<<0<<endl;
    while(end.x != n - 1 || end.y != n - 1)
    {
        printf("%d %d\n", pre[end.x][end.y].x, pre[end.x][end.y].y);
        int x = end.x, y = end.y;
        end.x = pre[x][y].x, end.y = pre[x][y].y;
    }
    return 0;
}