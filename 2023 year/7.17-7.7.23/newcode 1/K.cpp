#include <iostream>
using namespace std;

const int N = 1e5+50;
int e[N*2],ne[N*2],h[N],cnt;

void add(int u,int v){
    e[cnt] = v;
    ne[cnt] = h[u];
    h[u] = cnt ++;
}


int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i ++){
        int u,v;
        cin >> u >> v;
        add(u,v);
        add(v,u);
    }0
    return 0;
}