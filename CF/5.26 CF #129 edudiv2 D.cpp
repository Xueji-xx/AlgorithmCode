#include<iostream>
#include<string>
using namespace std;
#include<map>
#include<queue>
#define ll long long

int main(){
	ll n,x;
	cin>>n>>x;
	queue<ll> q;
	map<ll,int> a;
	a[x] = 0;
	q.push(x);
	bool flag = true;
	while(!q.empty()){
		ll k = q.front();
		q.pop();
		string s = to_string(k);
		if(s.length() == n){
			cout<<a[k]<<endl;
			flag = false;
			break;
		}
		for(auto i:s){
			if(i == '0')continue;
			ll c = k*(i - '0');
			if(!a.count(c)){
				a[c] = a[k] + 1;
				q.push(c);
			}
		}
	}
	if(flag)cout<<-1<<endl;
	return 0;
}
