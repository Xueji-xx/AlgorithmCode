#include <iostream>
#include <string.h>
using namespace std;

int a[50],f[50];

void solve(){
	memset(a,0,sizeof a);
	int l,r;
	cin>>l>>r;
	int m = r - l + 1;
	for(int i = 1;i <= m;i ++){
		int x;
		cin>>x;
		for(int j = 17;j >= 0;j --){
			if(x & f[j])a[j]++;
		}
	}
	int ans = 0;
	for(int j = 17;j >= 0;j --){
		if(a[j] * 2 > m)ans |= f[j];
	}
	cout<<ans<<endl;
}


int main(){
	int t;
	cin>>t;
	f[0] = 1;
	f[1] = 1;
	for(int i = 2;i <= 35;i ++){
		f[i] = f[i-1] * 2;
	}
	while(t--)solve();
	return 0;
}
