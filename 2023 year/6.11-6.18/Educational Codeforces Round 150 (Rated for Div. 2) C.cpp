#include <iostream>
#include <cmath>
using namespace std;


void solve(){
	string s;
	cin >> s;
	int sum = 0;
	int n = s.length();
	for(int i = 0;i < n;i ++){
		bool flag = false;
		for(int j = i + 1;j < n;j ++){
			if(s[j] > s[i]){
				flag = true;
				break;
			}
		}
		if(flag){
			sum -= pow(10,s[i] - 'A');
		}
		else sum += pow(10,s[i] - 'A');
	}
	cout << sum << endl;
}


int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}
