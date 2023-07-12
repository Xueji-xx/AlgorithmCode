#include<iostream>
using namespace std;

void solve(){
	int t;
	cin>>t;
	int a[t];
	for(int i = 0;i < t;i ++){
		cin>>a[i];
	}
	int x,y;
	x = y = 0;
	for(int i = 0;i < t;i ++){
		if(a[i] & 1)x++;
		else y++;
	}
	cout<<min(x,y)<<endl;
}


int main(){
	int n;
	cin>>n;
	while(n--)solve();
	return 0;
}
