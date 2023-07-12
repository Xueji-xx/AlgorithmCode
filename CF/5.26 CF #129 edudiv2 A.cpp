#include<iostream>
using namespace std;


void solve(){
	int n;
	cin>>n;
	int a[n] = {0};
	int l = 0,r = 0; 
	for(int i = 0;i < n;i ++){
		cin>>a[i];
		l = max(l,a[i]);
	}
	int m;
	cin>>m;
	int b[m];
	for(int i = 0;i < m;i ++){
		cin>>b[i];
		r = max(r,b[i]);
	}
	if(l >= r){
		cout<<"Alice"<<endl;
	}
	else cout<<"Bob"<<endl;
	if(r >= l){
		cout<<"Bob"<<endl;
	}
	else cout<<"Alice"<<endl;
}



int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
