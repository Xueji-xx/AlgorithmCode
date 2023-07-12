#include <iostream>
using namespace std;

bool vis[20][20];
int ans;
int mov[] = {0,1,0,-1,0};

void dfs(int x,int y,int cnt){
	if(cnt == 15){
		ans ++;
		return;
	}
	for(int i = 0;i < 4;i ++){
		int xx = x + mov[i];
		int yy = y + mov[i+1];
		if(xx >= 0 && xx < 4 && yy >= 0 && yy < 4 && !vis[xx][yy]){
			vis[xx][yy] = 1;
			dfs(xx,yy,cnt+1);
			vis[xx][yy] = 0;
		}
	}
}


int main(){
	for(int i = 0;i < 4;i ++){
		for(int j = 0;j < 4;j ++){
			vis[i][j] = 1;
			dfs(i,j,0);
			vis[i][j] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
