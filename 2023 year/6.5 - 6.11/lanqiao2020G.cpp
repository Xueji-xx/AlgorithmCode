#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e6+50;

string a[10050];
string b[10050];
int dp[N];

int main(){
	string s;
	cin >> s;
	s += 'X';
	int last = 0;
	for(int i = 0;i < s.length();i ++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			a[i] = s.substr(last,i);
			last = i;
		}
	}
	int maxm = 0;
	int cnt = 0;
	for(int i = 0;i < a.size();i ++){
		dp[i] = 1;
		for(int j = 0;j < i;j ++){
			if(strcmp(s[i],s[j]) < 0){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		if(dp[i] >= maxm){
			maxm = dp[i];
			cnt = i;
		}
	}
	int x = 0;
	for(int i = cnt;i >= 0;i --){
		if(maxm == dp[i]){
			b[x ++] = a[i];
			maxm --;
		}
	}
	for(int i = 0;i < x;i ++){
		cout << b[i];
	}
	return 0;
}
