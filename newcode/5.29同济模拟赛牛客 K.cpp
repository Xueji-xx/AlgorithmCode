#include<iostream>
using namespace std;
const int N = 1e3+50;
int a[N][N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n;i ++){
		string s;
		cin>>s;
		for(int i = 0;i < s.length();i ++){
			a[i][s[i]-'A']++;
		}
	}
	int ans = 0;
	for(int i = 0;i < m;i ++){
		int x;cin>>x;
		int maxm = 0;
		for(int j = 0;j < 5;j ++){
			maxm = max(maxm,a[i][j]);
		}
		ans += x*maxm;
	}
	cout<<ans;
	return 0;
}
