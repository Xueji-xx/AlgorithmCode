#include <iostream>
using namespace std;
const int N = 2e3 + 10;

int a[N][N];
int n;

int cal(int x,int y){
	int cnt = 0;
	while(y <= n){
		cnt += a[x][y];
		x = x % n + 1;
		y ++;
	}
	return cnt;
}

void solve(){
	cin>>n;
	int s = 0;
	int maxm = -999;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			char c;
			cin>>c;
			if(c == '1'){
				a[i][j] = 1;
				s++;
			}
			else a[i][j] = 0;
		}
	}
	for(int i = 1;i <= n;i ++){
		maxm = max(maxm,cal(i,1));
	}
	cout<<n - maxm + s - maxm<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
