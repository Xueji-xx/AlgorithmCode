#include <iostream>
#include <string.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5+50;
int a[N],b[N];

void solve(){
    int n,k;
    cin>>n>>k;
    memset(b,0,sizeof b);
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        int x = 999999999;
        for(int l = 1,r;l <= min(k,a[i]);l = r+1){
            int t = a[i] / l;
            r = a[i] / t;
            b[t+1] = max(b[t+1],x);
            x = t;
        }
        b[0] = max(b[0],x);
    }
    int ans = 99999999,maxm = 0;
    for(int i = 0;i <= a[1];i ++){
        maxm = max(maxm,b[i]);
        ans = min(ans,maxm - i);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}