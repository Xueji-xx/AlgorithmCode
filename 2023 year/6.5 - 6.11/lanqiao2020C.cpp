#include <iostream>
using namespace std;

#define int long long
int p[150];

signed main(){
	int ans = 1;
	for(int i = 2;i <= 100;i ++){
		int n = i;
		for(int j = 2;j <= n / j;j ++){
			while(n % j == 0){
				p[j] ++;
				n /= j;
			}
		}
		if(n > 1)p[n] ++;
	}
	for(int i = 2;i <= 100;i ++){
		if(p[i]) ans *= (p[i] + 1);
	}
	cout << ans << endl;
	return 0;
} 
