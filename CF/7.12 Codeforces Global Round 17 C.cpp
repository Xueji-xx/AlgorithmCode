#include<iostream>
using namespace std;
const int N = 2e5+10;
int a[N],b[N],n;

bool check(int x){
	int cnt = 0;
	for(int i = 1;i <= n;i ++){
		if(b[i] >= cnt && x - cnt -1 <= a[i])cnt++;
	}
	if(cnt >= x)return true;
	else return false;
}

void solve(){
	cin>>n;
	for(int i = 1;i <= n;i ++)cin>>a[i]>>b[i];
	int l = 1,r = n;
	while(l < r){
		int mid = (l+r+1)/2;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid-1;
		}
	}
	cout<<l<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
