#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int a[100];
int tot[100]; 


void dfs(int dep,int pos,int sum){
	if(dep == m+1){
		bool flag = false;
		for(int i = 1;i <= n;i ++){
			if(sum == a[i]){
				flag = true;
				break;
			}
		}
		if(flag){
			for(int i = 1;i <= m;i ++){
				if(i < m)cout << tot[i] << '+';
				else cout << tot[i] << '=' << sum << endl;
			}
		}
		return;
	}
	for(int i = pos;i <= n;i ++){
		if(sum + a[i] <= a[n]){
			tot[dep] = a[i];
			dfs(dep+1,i+1,sum + a[i]);
		}
	}
}

int main(){
	cin >> n;
	
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(m = 2;m <= n-1;m ++){
		dfs(1,1,0);
	}
	return 0;
} 
