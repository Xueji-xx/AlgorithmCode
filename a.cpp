#include <iostream>
#include <math.h>
using namespace std;

#define ll long long

int main(){
	ll m,n;
	cin >> m >> n;
	int ans = 0;
	for(int i = 1;i <= 2000;i ++){
		if(i * i * i >= m && i * i * i <= n)ans ++;
	}
	cout << ans << endl;
	return 0;
} 
