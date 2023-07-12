#include <iostream>
using namespace std;



int main(){
	string s;
	cin>>s;
	for(int i = 0;i < s.length();i ++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			cout<<i+1<<endl;
			break;
		}
	}
	return 0;
} 
