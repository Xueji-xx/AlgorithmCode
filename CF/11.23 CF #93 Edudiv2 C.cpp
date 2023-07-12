#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+7;
ll a[maxn],b[maxn],c[maxn];
string str;
map<ll,ll> mp; 
int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n;
		scanf("%lld",&n);
		cin>>str;
		mp.clear();
		ll sum=0;
		for(int i=0;i<str.size();i++){
			a[i+1]=a[i]+(str[i]-'0')-1;
			if(a[i+1]==0) sum++;
			sum+=mp[a[i+1]];
			mp[a[1+i]]++;
		}
		cout<<sum<<endl;
	}
	return 0;
}