#include<iostream>
using namespace std;
#define ll long long

void solve(){
	ll x;
	cin>>x;
	if((x & 1)&&x != 1)cout<<1<<endl;
	else if((x & 1) && (x == 1))cout<<3<<endl;
	else{
		int cnt = 0;
		while(x){
			x >>= 1;
			cnt++;
			if(x&1)break;
		}
		int ans = 1;
		if(x == 1)cout<<(ans<<cnt)+1<<endl;
		else cout<<(ans<<cnt)<<endl;
	}
}


int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
