#include<iostream>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;

void solve(){
	int n;
	cin>>n;
	bool flag = false;
	set<string> two,three;
	while(n--){
		string s;
		cin>>s;
		if(s.length() == 1){
			flag = true;
		}
		else{
			if(s.length() == 2){
				if(s[0] == s[1]){
					flag = true;
				}
				else{
					string a = s;
					reverse(a.begin(),a.end());
					if(two.count(a)){
						flag = true;
					}
					for(char i = 'a';i <= 'z';i ++){
						if(three.count(a+i)){
							flag = true;
						}
					}
					two.insert(s);
				}
			}
			else{
				if(s[0] == s[2]){
					flag = true;
				}
				else{
					string a = s;
					reverse(a.begin(),a.end());
					a.pop_back();
					if(two.count(a)){
						flag = true;
					}
					a = s;
					reverse(a.begin(),a.end());
					if(three.count(a)){
						flag = true;
					}
					three.insert(s);
				}
			}
		}
	}
	if(!flag)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	system("pause");
	return 0;
} 
