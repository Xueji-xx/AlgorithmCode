#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define int long long
const int N = 2e6+50;
int e[N],ne[N],h[N],cnt;
int d[N];
int q[N];
int n,m;
int t;

void add(int u,int v){
    e[++cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt;
}

bool topsort(){
    int hh = 0,tt = -1;
    for(int i = 1;i <= n;i ++){
        if(!d[i]){
            q[++tt] = i;
        }
    }
    while(hh <= tt){
        int t = q[hh ++];
        for(int i = h[t]; i ;i = ne[i]){
            int j = e[i];
            if(!--d[j])q[++tt] = j;
        }
    }
    t = tt;
    return tt == n-1;
}

signed main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int a,b;
        cin >> a >> b;
        add(b,a);
        d[a] ++;
    }
    if(!topsort()){
        cout << 2 << endl;
        for(int i = 1;i <= n;i ++)cout << i << ' ';
        cout << endl;
        for(int i = n;i >= 1;i --)cout << i << ' ';
        cout << endl;
    }
    else{
        cout << 1 << endl;
        for(int i = t;i >= 0;i --){
            cout << q[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}