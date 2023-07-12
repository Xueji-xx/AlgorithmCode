#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1050;
int A[N][N];
int d[N][N];
int mov[] = {0,-1,0,1,0};
typedef pair<int,int> PII;
queue<PII> q;


int main(){
	int n,m;
	cin >> n >> m;
	getchar();
	for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            char ch = getchar();
            A[i][j] = ch-'0';
            d[i][j] = -1;
            if(A[i][j]){
                d[i][j] = 0;
                q.push({i,j});
            }
        }
        getchar();
    }

	/*for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}*/
	while(q.size()){
		auto t = q.front();
		q.pop();
		for(int i = 0;i < 4;i ++){
			int xx = t.first + mov[i];
			int yy = t.second + mov[i+1];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && d[xx][yy] == -1){
				d[xx][yy] = d[t.first][t.second] + 1;
				q.push({xx,yy}); 
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
