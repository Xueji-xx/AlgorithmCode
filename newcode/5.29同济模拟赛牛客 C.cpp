#include<iostream>
using namespace std;
#define ll long long
const int N = 1e6+10;
ll a[100005];
void solve(){
	int n;
	cin>>n;
	
	ll minn = 1e17;
	ll sum = 0;
	for(int i = 0;i < n;i ++){
		cin>>a[i];
		sum += a[i];
		minn = min(minn,a[i]);
	}
	if(n == 1 || n == 0){
		cout<<"YES"<<endl;
	}
	else if(sum % (6+n) == 0 && minn >= sum/(6+n))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
