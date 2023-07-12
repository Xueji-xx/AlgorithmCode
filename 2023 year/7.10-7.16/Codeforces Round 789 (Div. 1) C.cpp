#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


#define int long long
const int N = 1e5+50;
bool vis[N];
int ne[N];
int dfs(int p){
    int res = 1;
    vis[p] = true;
    while(1){
        p = ne[p];
        if(vis[p])break;
        vis[p] = true;
        res ++;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    int a[n+10] = {0};
    int b[n+10] = {0};
    
    for(int i = 1;i <= n;i ++)cin >> a[i];
    for(int i = 1;i <= n;i ++)cin >> b[i];
    for(int i = 1;i <= n;i ++){
        ne[a[i]] = b[i];
    }
    int sum = 0;
    int tmp = 0;
    memset(vis,false,sizeof vis);
    for(int i = 1;i <= n;i ++){
        if(vis[i])continue;
        int res = dfs(i);
        tmp += res / 2; 
    }
    for(int i = 0;i < tmp;i ++){
        sum += (n - 1 - 2 * i) * 2;
    }
    cout << sum << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}