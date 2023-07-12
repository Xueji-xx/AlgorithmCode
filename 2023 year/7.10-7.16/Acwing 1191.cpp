#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int N = 200;
int e[N],ne[N],h[N];
int cnt;
queue<int> q;
int d[N];
int n;
int x = 0;
int a[N];

void add(int u,int v){
    e[cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt ++;
}

void topsort(){
    for(int i = 1;i <= n;i ++){
        if(!d[i])q.push(i);
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        a[++x] = t;
        for(int i = h[t]; ~i ;i = ne[i]){
            int j = e[i];
            if(--d[j] == 0){
                q.push(j);
            }
        }
    }
}

int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 1;i <= n;i ++){
        int son;
        while(cin >> son , son){
            add(i,son);
            d[son] ++;
        }
    }
    topsort();
    for(int i = 1;i <= x;i ++)cout << a[i] << ' ';
    return 0;
}