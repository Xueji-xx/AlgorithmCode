#include <iostream>
using namespace std;

const int N = 1e5+50;
int n,k;
typedef pair<int,int> PII;
PII q[N];
bool vis[N];


int bfs(){
	int h = 0,t = 1;
	q[0] = {n,0};
	vis[n] = true;
	while(h < t){
		PII now = q[h++];
		if(now.first == k){
			return now.second;
		}
		if(now.first + 1 <= k && !vis[now.first + 1]){
			q[t++] = {now.first + 1,now.second + 1};
			vis[now.first+1] = true;
		}
		if(now.first - 1 >= 0 && !vis[now.first - 1]){
			q[t++] = {now.first - 1, now.second + 1};
			vis[now.first - 1] = true;
		}
		if(now.first << 1 <= N && now.first < k && !vis[now.first << 1]){
			q[t++] = {now.first << 1 , now.second + 1};
			vis[now.first << 1] = true;
		}
	}	
}


int main(){
    cin >> n >> k;
  	cout << (n < k ? bfs() : n - k); 
    return 0;
}
