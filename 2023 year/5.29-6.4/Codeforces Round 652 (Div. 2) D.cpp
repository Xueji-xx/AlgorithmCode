#include <iostream>
using namespace std;

typedef long long ll;
const int N = 2e6+50;
const ll mod = 1e9 + 7;

int d[N] = {0,0,0,1,0,0};
ll ans[N] = {0,0,0,4,4};


int main(){
	int t;
	cin >> t;
	for(int i = 5;i <= N - 1;i ++){
		ans[i] = ans[i-2] * (long long)2 + ans[i-1];
		if(d[i-1] == 0 && d[i-2] == 0)d[i] += 4;
		ans[i] += d[i];
		ans[i] %= mod;
	}
	while(t --){
		int n;
		cin >> n;
		cout << ans[n]<< endl;
	}
	return 0;
} 
