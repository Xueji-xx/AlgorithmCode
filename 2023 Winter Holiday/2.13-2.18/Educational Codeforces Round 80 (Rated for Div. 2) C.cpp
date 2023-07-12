#include <iostream>
using namespace std;
#define int long long

const int mod = 1e9+7;

int qpow(int a,int b){
	int res = 1;a %= mod;
	while(b){
		if(b & 1){
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int C(int a,int b){
	int up = 1,down = 1;
	for(int i = 0;i < b;i ++){
		up = up * (a - i) % mod;
		down = down * (b - i) % mod;
	}
	down = qpow(down,mod - 2);
	return up * down % mod;
}

signed main(){
	int n,m;
	cin>>n>>m;
	cout<<C(2*m+n-1,n-1)<<endl;
	return 0;
} 
