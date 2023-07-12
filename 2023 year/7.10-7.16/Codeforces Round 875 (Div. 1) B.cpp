#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define int long long
const int N = 2e5+50;
int a[N],b[N];
int cnt[N];
int p[N];

bool cmp(int i,int j){
    return a[i] < a[j];
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)cin >> a[i];
    for(int i = 0;i < n;i ++)cin >> b[i];
    for(int i = 0;i < n;i ++)p[i] = i;
    sort(p,p+n,cmp);
    int res = 0;
    for(int i = 1;i * i <= n << 1;i ++){
        memset(cnt,0,sizeof cnt);
        for(int j = 0;j < n;j ++){
            int t = i * a[p[j]] - b[p[j]];
            if(t >= 1 && t <= n)res += cnt[t];
            if(i == a[p[j]])cnt[b[p[j]]] ++;
        }
    }
    cout << res << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}