#include<iostream>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int x = n/3;
	for(int i = x;i <= n;i ++){
		for(int j = i-10;j < i;j ++){
			for(int k = j-10;k < j;k ++){
				if(i+j+k == n){
					cout<<j<<' '<<i<<' '<<k<<endl;
					return;
				}
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
