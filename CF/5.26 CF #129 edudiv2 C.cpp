#include<iostream>
using namespace std;

typedef pair<int,int> PII;


void solve(){
	int n;
	cin>>n;
	PII s[10050];
	int a[n],b[n];
	for(int i = 0;i < n;i ++){
		cin>>a[i];
	}
	for(int i = 0;i < n;i ++){
		cin>>b[i];
	}
	int cnt = 0;
	for(int i = 0;i < n-1;i ++){
		for(int j = i+1;j < n;j ++){
			if(a[i] > a[j] || (a[i] == a[j] && b[i] > b[j])){
				swap(a[i],a[j]);
				swap(b[i],b[j]);
				s[cnt++] = {i,j};
			}
		}
	}
	bool flag = true;
	for(int i = 0;i < n-1;i ++){
		if(a[i] > a[i+1] || b[i] > b[i+1]){
			flag = false;
			break;
		}
	}
	if(!flag)cout<<-1<<endl;
	else{
		cout<<cnt<<endl;
		for(int i = 0;i < cnt;i ++){
			cout<<s[i].first+1 <<' '<<s[i].second+1<<endl;
		}
	}
}



int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
