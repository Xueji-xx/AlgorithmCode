#include<iostream>
using namespace std;
#define ll long long 
#define mod 6662333
int main(){
	ll n;
	cin>>n;
	ll p = 2;
	ll ans = 1;
	n--;
	while(n){
		if(n & 1)ans = ans * p % mod;
		n >>= 1;
		p = (p*p)%mod;
	}
	cout<<ans;
	return 0;
}
