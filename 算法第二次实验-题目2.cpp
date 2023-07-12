#include <iostream>
using namespace std;
const int N = 300;

const int INF = 0x3f3f3f3f; 

int d[N][N];
int n;
void floyd(){
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
}

int main(){
	cout<<"输入村庄数量:";
	cin >> n;
	cout << "输入边:" << endl;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(i == j)d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	int m = n - 1;
	while(m --){
		int x,y;
		cin >> x >> y;
		d[x][y] = d[y][x] = 1;
	}
	floyd();
	int ans;
	int minn = 999999;
	for(int i = 1;i <= n;i ++){
		int maxm = 0;
		for(int j = 1;j <= n;j ++){
			if(i == j)continue;
			else{
				maxm = max(maxm,d[i][j]);//找到距离最远的点的长度 
			}
		}
		//cout << maxm << ' ' << minn << endl;
		if(maxm <= minn){
			minn = maxm;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
} 
