#include<iostream>
#include<string.h>
using namespace std;
const int N = 1e5+10;
int n,m;
int h[N],e[N],idx,ne[N];
int dis[N];
int q[N];

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int bfs(){
	int head = 0,tail = 0;
	q[0] = 1;
	memset(dis,-1,sizeof dis);
	dis[1] = 0;
	while(head <= tail){
		int t = q[head++];
		for(int i = h[t];i != -1;i =ne[i]){
			int j = e[i];
			if(dis[j] == -1){
				dis[j] = dis[t] + 1;
				q[++tail] = j;
			}
		}
	}
	return dis[n];
}

int main(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i = 0;i < m;i ++){
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	cout<<bfs();
	return 0;
}
