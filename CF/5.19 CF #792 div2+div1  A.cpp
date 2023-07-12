#include<iostream>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(s.length() == 2){
			cout<<s[1]<<endl;
		}
		else{
			int x = s[0] - '0';
			int min = x;
			for(int i = 0;i < s.length();i ++){
				if(x > s[i] - '0'){
					min = s[i]-'0';x = s[i] - '0';
				}
				if(min == 1){
					break;
				}
			}
			cout<<min<<endl;
		}
	}
	
	
	return 0;
}
