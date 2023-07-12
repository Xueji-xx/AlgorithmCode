#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define double long double
const double esp = 1e-12;
typedef pair<double,int> PII;
PII ans[50];
int p[50];
int map[50][25];
bool vis[25];

bool cmp(PII a,PII b){
	if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> p[i];
	}
	for(int i = 1;i <= n;i ++){
		ans[i].second = i;
		for(int j = 1;j <= m;j ++){
			cin >> map[i][j];
		}
	}
	int k;
	cin >> k;
	for(int i = 1;i <= k;i ++){
		int x;
		cin >> x;
		vis[x] = true;
	}
	double bot = 0.0;
	for(int i = 1;i <= n;i ++){
		double t = p[i] / 100.0;
		//cout << t << ' ';
		for(int j = 1;j <= m;j ++){
			if(vis[j])t *= ((double)map[i][j] / 100.0);
			else t *= ((double)(100 - map[i][j]) / 100.0);
		}
		//cout << t << endl;
		ans[i].first = t;
		bot += t;
	}
	sort(ans+1,ans+1+n,cmp);
	for(int i = 1;i <= n;i ++){
		double t = (abs(bot) < esp) ? 0.0 : 100 * ans[i].first / bot;
		printf("%d %.2LF\n",ans[i].second,t);
	}
	return 0;
} 
