#include<iostream>
using namespace std;
const int N = 1e6+7;
typedef long long ll;
string s,s1;

bool cmp(string s,string s1){
	string k ;
	string kk ;
	int a=0,b=0,c=0;
	int aa=0,bb=0,cc=0;
	for(int i = 0;i<s.length();i++){
		if(s[i]=='a') a++;
		else if(s[i]=='b')b++;
		else c ++;
		if(s1[i]=='a') aa++;
		else if(s1[i]=='b')bb++;
		else cc++;
		if(a<aa) return 1;
		if(cc<c) return 1;
		if(s[i]!='b') k+=s[i];
		if(s1[i]!='b') kk+=s1[i]; 
	}
	if(kk!=k) return 1;
	else return 0;
}


int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
        cin>>n;
		cin>>s>>s1;
		if(!cmp(s,s1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}