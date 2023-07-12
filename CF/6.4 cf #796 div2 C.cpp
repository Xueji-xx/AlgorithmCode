#include<iostream>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int a[26] = {0};
	for(int i = 0;i <= 2*n;i ++){
		string s;
		cin>>s;
		for(auto i:s){
			a[i-'a']++;
		}
	}
	for(int i = 0;i < 26;i ++){
		if(a[i] & 1){
			cout<<char(i+'a')<<endl;
			break;
		}
	}
}


int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
