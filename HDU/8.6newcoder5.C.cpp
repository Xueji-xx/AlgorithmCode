#include<iostream>
#define int long long
using namespace std;

const int N = 1e6+10;
int a[N][3];
int n,x;
string s,ans;
int cnt;

void solve(){
    cin>>n;
	for(int i = 1;i <= n*3;i ++){
		cin>>x;
		cin>>s;
		if(s[0] == 'Y')a[x][1]++;		
		else a[x][0]++;
	}
	bool flag = 0;
	for(int i = 0;i < n;i ++){
		if(!a[i][0] && !a[i][1]){
			//0 0
			cout<<-1<<endl;
			return;
		}
		else if(a[i][0] >= 2 && a[i][1] >= 2){
			//3 3
			cout<<-1<<endl;
			return;
		}
		else if(a[i][0] == 1 && a[i][1] == 1){
			// 1 1
			cout<<-1<<endl;
			return;
		}
		else if(!a[i][0] && a[i][1] > 1)ans += '1';//0 5
		else if(!a[i][1] && a[i][0] > 1)ans += '0';//5 0
		else if(a[i][0] + a[i][1] == 1){
			//0 1
			//1 0
			flag = true;
			if(a[i][1])ans += '1';
			else ans += '0';
		}
		else{
			//x 1
			//1 x
			cnt++;
			if(a[i][1] == 1)ans += '0';
			else ans += '1';
		}
	}
	if(cnt > 1){
		cout<<-1<<endl;
		return;
	}
	else if(cnt == 1)cout<<ans<<endl;
	else if(cnt == 0 && flag == true){
		cout<<-1<<endl;
	}
	else cout<<ans<<endl;
}
	

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solve();
    return 0;
}