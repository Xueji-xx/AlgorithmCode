#include<iostream>
using namespace std;
typedef pair<long long,long long> PII;
const int N = 5e4+50;

void solve(){
	long long n;
	cin>>n;
	long long a[N],b[N];
	PII c[N];
	long long q = 1e9;
	bool flag = true;
	for(long long i = 0;i < n;i ++)cin>>a[i];
	for(long long i = 0;i < n;i ++){
		cin>>b[i];
		if(b[i] > a[i]){
			flag = false;
		}
		c[i].first = a[i] - b[i];
		c[i].second = 1;
		if(b[i] == 0)c[i].second = 0;
		else q = c[i].first;
	}
	if(!flag){
		cout<<"NO"<<endl;
		return;
	}
	if(n == 1){
		cout<<"YES"<<endl;
		return;
	}
	for(long long i = 0;i < n;i ++){
		if(c[i].first != q){
			if(c[i].first < q && c[i].second == 0){
				continue;
			}
			else{
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	cout<<"YES"<<endl;
}

int main(){
	long long t;
	cin>>t;
	while(t--)solve();
	return 0;
}
