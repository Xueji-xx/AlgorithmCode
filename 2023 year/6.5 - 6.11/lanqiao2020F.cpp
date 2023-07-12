#include <iostream>
#include <math.h>
using namespace std;
#define int long long

int qmi(int a,int n){
	int res = 1;
	while(n){
		if(n % 2 == 1){
			res *= a;
			n --;
		}
		a *= a;
		n /= 2;
	}
	return res;
}


int dfs(int n,int x,int y){
	if(n == 0)return 1;
	if(n >= 40)n = 39;
	int k = qmi(3,n-1);
	int xx = x % k;
	int yy = y % k;
	int a = x / k;
	int b = y / k;
	if(a==0&&b==0)     return 0*k*k+dfs(n-1,xx,yy);
	else if(a==0&&b==1)return 1*k*k+dfs(n-1,k-1-xx,yy);
	else if(a==0&&b==2)return 2*k*k+dfs(n-1,xx,yy);
	else if(a==1&&b==2)return 3*k*k+dfs(n-1,xx,k-1-yy);
	else if(a==1&&b==1)return 4*k*k+dfs(n-1,k-1-xx,k-1-yy);
	else if(a==1&&b==0)return 5*k*k+dfs(n-1,xx,k-1-yy);
	else if(a==2&&b==0)return 6*k*k+dfs(n-1,xx,yy);
	else if(a==2&&b==1)return 7*k*k+dfs(n-1,k-1-xx,yy);
	else if(a==2&&b==2)return 8*k*k+dfs(n-1,xx,yy); 
}	


signed main(){
	int n;
	cin >> n;
	int x1,y1,x2,y2;
	cin >> x1 >>y1 >> x2 >> y2;
	int ans = dfs(n,x1,y1) - dfs(n,x2,y2);
	if(ans < 0)ans *= -1;
	cout << ans << endl;
	return 0;
}
