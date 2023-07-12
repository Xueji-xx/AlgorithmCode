#include <iostream>
#include <string.h>
using namespace std;

const int N = 1050;
int map[N][N];
const int inf = 2e9+50;
int c[N];
bool vis[N];
int dis[N];
int n,m;

int find(){
	int now = 0,min_dis = inf;
	for(int i = 1;i <= n;i ++){
		if(!vis[i] && dis[i] < min_dis){
			min_dis = dis[i];
			now = i;
		}
	}
	return now;
}

int dijkstra(){
	for(int i = 2;i <= n;i ++){
		dis[i] = map[1][i] + c[i];
	}
	dis[1] = 0;
	vis[1] = true;
	int now = find();
	while(now){
		for(int i = 2;i <= n;i ++){
			dis[i] = min(dis[i],dis[now] + map[i][now] + c[i]);
		}
		vis[now] = true;
		now = find();
	}
	return dis[n] - c[n];
}



int main(){
	cin >> n >> m;
	memset(vis,false,sizeof vis);
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			map[i][j] = inf;
		}
		dis[i] = inf;
		map[i][i] = 0;
	}
	for(int i = 1;i <= n;i ++){
		cin >> c[i];
	}
	while(m --){
		int u,v,w;
		cin >> u >> v >> w;
		map[u][v] = w;
		map[v][u] = w;
	}
	cout << dijkstra();
	return 0;
}
