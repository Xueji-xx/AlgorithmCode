#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
#define fir(i,a,b) for(int i=a;i<=b;i++)
struct node{
    int x,y;
};
const int N = 510;
char s[N][N];
const int dxy1[4][2]= {{1,1},{-1,-1},{1,-1},{-1,1}},dxy2[4][2]= {{1,1},{0,0},{1,0},{0,1}};
deque<node> q;

int t,n,m,ans = 1e8,dis[N][N];
bool vis[N][N];

int check(int x,int y){
    return x >= 0 && x <= n && y >= 0 && y <= m;
}

void bfs(){
    vis[0][0]=1;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));//初始化最大值
    q.push_front(node {0,0});//0开始,是因为读入的不是坐标,而是两种线路,然后你就会发现其实坐标点是要从0开始的,当然你n+1,m+1也是可以的
    dis[0][0]=0;
    while(q.size())
    {
        node now=q.front();
        q.pop_front();
        fir(i,0,3)//四种方向
        {
            int tx=now.x+dxy1[i][0],t1=now.x+dxy2[i][0];//如果是'\'
            int ty=now.y+dxy1[i][1],t2=now.y+dxy2[i][1];//如果是'/'
            int tt=(s[t1][t2] != (i<=1? '\\':'/'));//转义字符要双写,这里用到了三目运算符
            if(check(tx,ty) && dis[tx][ty]>dis[now.x][now.y]+tt)//check成功,并且当前值更加优秀
            {
                dis[tx][ty]=dis[now.x][now.y]+tt;
                if(tt)
                    q.push_back(node {tx,ty});//边权值为1
                else
                    q.push_front(node {tx,ty});//边权值为0
            }
        }
    }
}

void solve(){
    
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> s[i][j];
        }
    }
    bfs();
    if(dis[n][m] < 1e8){
        cout << dis[n][m] << endl;
    }
    else cout << "NO SOLUTION" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}