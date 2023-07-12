#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
void solve(){
	ll n;
	cin>>n;
	ll a[n];
	ll odd = 0,even = 0;
	for(ll i = 0;i < n;i ++){
		cin>>a[i];
		if(a[i] & 1)odd++;
		else even++;
	}
	ll ans = 1000000000;
	if(even == 0)cout<<0<<endl;
	else if(even && odd)cout<<even<<endl;
	else if(odd == 0){
		sort(a,a+n);
		for(int i = 0;i < n;i ++){
			ll res = 0;
			while(1){
				a[i] /= 2;
				res++;
				if(a[i] & 1)break;
			}
			ans = min(ans,res);
		}
		cout<<ans+even-1<<endl;
	}
	
}

int main(){
	ll t;
	cin>>t;
	while(t--)solve();
	return 0;
}
