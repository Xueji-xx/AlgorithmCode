#include<iostream>
using namespace std;
#include<map>

void solve(){
	map<int,int>s;
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i < n;i ++){
		cin>>a[i];
	}
	for(int i = 0;i < n;i ++){
		s[a[i]]++;
	}
	map<int,int>::iterator iter;
	for(iter = s.begin();iter != s.end();iter ++){
		if((*iter).second < 2){
			cout<<-1<<endl;
			return;
		}
	}
	int cnt = 0;
	for(iter = s.begin();iter != s.end();iter ++){
		for(int i = 1;i <= (*iter).second;i ++){
			cout<<i%(*iter).second + 1 + cnt<<' ';
		}
		cnt += (*iter).second;
	}cout<<endl;
}



int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
