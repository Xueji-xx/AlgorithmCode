#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e5+50;
int l[N],r[N];
int ans[N];
int op[N];
int n,m;

bool check(int x){
    int vis[n+10] = {0};
    int sum[n+10] = {0};
    for(int i = 1;i <= x;i ++){
        vis[op[i]] = 1;
    }
    for(int i = 1;i <= n;i ++)sum[i] = sum[i-1] + vis[i];
    for(int i = 1;i <= m;i ++){
        if(sum[r[i]] - sum[l[i] - 1] >= ans[i])return true;
    }
    return false;
}


int main(){
    int t;
    cin >> t;
    while(t --){
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        memset(ans,0,sizeof ans);
        memset(op,0,sizeof op);
        cin >> n >> m;
        for(int i = 1;i <= m;i ++){
            cin >> l[i] >> r[i];
            ans[i] = (r[i] - l[i] + 1) / 2 + 1;
        }
        int q;
        cin >> q;
        
        for(int i = 1;i <= q;i ++)cin >> op[i];
        int l = 1,r = q;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(mid))r = mid - 1;
            else l = mid + 1;
        }
        if(check(l))cout << l << endl;
        else cout << -1 << endl;
    }
    return 0;
}