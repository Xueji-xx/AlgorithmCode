#include<iostream>
using namespace std;




int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(((a-1)^(b-1)^(c-1)) != 0)cout<<"Win"<<endl;
		else cout<<"Lose"<<endl;
	}
	return 0;
} 
