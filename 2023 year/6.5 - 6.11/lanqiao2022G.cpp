#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3+50;
const int M = 5e3+50;
int dp[N][M]; //选到第 i 个的时候金额 j 是否能够选到 

typedef pair<int,int> PII;
PII a[N];


int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int get_day(int m,int d){
	int res = 0;
	for(int i = 0;i < m;i ++){
		res += mon[i];
	}
	return res + d;
}

bool cmp(PII a,PII b){
	return a.first < b.first;
}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	dp[0][0] = 1;
	for(int i = 1;i <= n;i ++){
		dp[i][0] = 1;
		int m,d;
		cin >> m >> d;
		cin >> a[i].second;
		a[i].first = get_day(m,d);
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n;i ++){
		int last = i - 1;
		while(a[i].first - k < a[last].first && last)last --;
		for(int j = m;j >= 0;j --){
			dp[i][j] = dp[i-1][j];
			if(j >= a[i].second)dp[i][j] |= dp[last][j - a[i].second];
		}
	}
	for(int i = m;i >= 0;i --){
		if(dp[n][i]){
			cout << i ;
			break;
		}
	}
	return 0;
}
