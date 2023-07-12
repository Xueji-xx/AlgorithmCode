#include<iostream>
#include<string.h>
#include<map>
using namespace std;

int a[202000],ans[202000];
bool f[202000];
map<int,bool>ma;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ma.clear();
		memset(f,0,sizeof f);
		for(int i = 1;i <= n;i ++){
			cin>>a[i];
			if(!ma.count(a[i])){
				ma[a[i]]=1;
			}
		}
		if(n == 1){
			printf("1\n1\n1\n");
			continue;
		}
		cout<<n-ma.size()<<endl;
		for(int i = 1;i <= n;i ++){
			int p=i;
			if(!ma.count(p)){
				int cnt=0;
				while(!f[p]){
					ans[++cnt]=p;
					f[p]=true;
					p=a[p];
				}
				cout<<cnt<<endl;
				for(int j = cnt;j >= 1;j --){
					cout<<ans[j]<<' ';
				}
				cout<<endl;
			}
		}
	}
	return 0;
}

