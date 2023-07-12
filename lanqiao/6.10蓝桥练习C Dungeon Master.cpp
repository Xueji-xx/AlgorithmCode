#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int l,r,c;//层数，行数，列数
char map[40][40][40];
int sx,sy,sz,fx,fy,fz;
bool vis[40][40][40];
struct node{
    int x,y,z;
    int step;
};
int mov[6][3] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};

bool judge(int x,int y,int z){
    if(x >= 0 && x < r && y >= 0 && y < c && z >= 0 && z < l && !vis[x][y][z] && map[x][y][z] != '#'){
        return true;
    }
    return false;
}

int bfs(){
    queue<node> q;
    node head,tail;
    head.x = sx;
    head.y = sy;
    head.z = sz;
    head.step = 0;
    q.push(head);
    while(!q.empty()){
        head = q.front();
        if(head.x == fx && head.y == fy && head.z == fz){
            
            return head.step;
        }
		q.pop();
        for(int i = 0;i < 6;i ++){
            tail.x = head.x + mov[i][0];
            tail.y = head.y + mov[i][1];
            tail.z = head.z + mov[i][2];
            if(judge(tail.x,tail.y,tail.z)){
                tail.step = head.step+1;
                vis[tail.x][tail.y][tail.z] = true;
                q.push(tail);
            }
        }
    }
    return 0;
}


int main(){
    while(cin>>l>>r>>c && l && r && c){
        for(int i = 0;i < l;i ++){
            for(int j = 0;j < r;j ++){
                for(int k = 0;k < c;k ++){
                    cin>>map[j][k][i];
                    if(map[j][k][i] == 'S'){
                        sx = j;
                        sy = k;
                        sz = i;
                    }
                    else if(map[j][k][i] == 'E'){
                        fx = j;
                        fy = k;
                        fz = i;
                    }
                }
            }
        }
	    memset(vis,0,sizeof vis);
	    int ans = bfs();
	    if(ans){
	        cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
	    }
	    else cout<<"Trapped!"<<endl;
    }
    return 0;
}
