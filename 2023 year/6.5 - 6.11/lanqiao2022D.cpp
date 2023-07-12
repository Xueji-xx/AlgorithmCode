#include <iostream>
using namespace std;
#define int long long

int n,a,b;
int bit = 1;
int res;

void dfs(int now,int x,int y,int f){
	res = max(res,now);
	if(x == 0 && y == 0)return;
	if(f == 0)return;
	int t = (now / f) % 10;
	if(x >= 9 - t)dfs(now + f * (9 - t),x - 9 + t,y,f / 10);
	else dfs(now + x * f,0,y,f / 10);
	if(y >= t + 1)dfs(now + f * (9 - t),x,y - t - 1,f / 10);
	else dfs(now,x,y,f / 10);
}


signed main(){
	cin >> n >> a >> b;
	while(n / bit >= 10)bit *= 10;
	dfs(n,a,b,bit);
	cout << res ;
	return 0;
}
