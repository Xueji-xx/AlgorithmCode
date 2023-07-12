#include<iostream>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int cnt = 0;int l = n,r = n;
	for(int i = 0;i < s.length();i ++){
		if(s[i] == '1'){
			cnt++;
			if(l == n)l = i;
			r = i;
		}
	}
	int sum = 0;
	//right
	if(cnt > 0 && n-1-r <= k){
		k -= (n-1-r);
		sum++;
		cnt--;
	}
	//left
	if(cnt > 0 && l <= k){
		sum += 10;
		cnt--;
	}
	cout<<11*cnt+sum<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
