#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int res = (1 << 20) - 1;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x != i) res &= x;
        }
        cout<<res<<endl;
	}
	
	return 0;
}
