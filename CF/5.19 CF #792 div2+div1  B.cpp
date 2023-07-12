#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		for(int i = 1;i < 10000;i ++){
			if((i*b + a) > c){
				cout<<i*b+a<<' '<<b<<' '<<i*b+a+c<<endl;
				break;
			}
		}
	}
	
	return 0;
}
