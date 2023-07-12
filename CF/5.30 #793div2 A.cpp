#include<iostream>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ans = 1;
		int l = s.length()/2 - 1;
		int r = s.length()/2 + 1;
		int flag1 = 1;
		while(1){
			if(s[l] == s[s.length()/2]){
				l--;
				ans++;
			}
			else break;
		}
		while(1){
			if(s[r] == s[s.length()/2]){
				r++;
				ans++;
			}
			else break;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
