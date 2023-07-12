#include<iostream>
#include<math.h>
using namespace std;
#define ll long long 
ll gcd(ll a,ll b) {    
    return b ? gcd(b,a%b):a;
}

void solve(){
	ll n,a;
	cin>>n>>a;
	ll su = a,hun = n-a;
	ll o = hun*hun*hun;
	ll t = hun*hun*su*3;
	ll s = hun*su*su*3;
	ll sum = o+t+s;
	ll c = gcd(o,sum);
	cout<<o/c<<'/'<<sum/c<<endl;
}

int main(){
	ll t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
