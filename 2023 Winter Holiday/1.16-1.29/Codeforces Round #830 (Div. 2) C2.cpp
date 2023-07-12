#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5+100;
int a[N],pres[N],prex[N],nex[N];

bool check(int ql,int qr,int ans,int mid,int &ansl, int &ansr){
    for(int i = ql, j = 1; j <= 32; i = nex[i], j ++){
        int l = i, r = i + mid - 1;
        r = min(r, qr);
        int res = pres[r] - pres[l - 1] - (prex[r] ^ prex[l - 1]);
        if(res == ans) {
            ansl = l, ansr = r;
            return true;
        }
        if(r == qr) return false;
        if(!nex[i] || nex[i] > qr) return false;
    }
    return false;
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        pres[i] = pres[i-1] + a[i];
        prex[i] = prex[i-1] ^ a[i];
    }
    int poi = 0;
    for(int i = n;i >= 1;i --){
        nex[i] = poi;    
        if(a[i])poi = i;
    }
    while(q--){
        int ql,qr;
        cin>>ql>>qr;
        if(!nex[ql] || nex[ql] > qr){
            cout<<ql<<' '<<ql<<endl;
            continue;
        }
        int l = 1,r = qr - ql + 1;
        int ans = pres[qr] - pres[ql - 1] - (prex[qr] ^ prex[ql - 1]);
        int ansl = 1,ansr = r;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(ql,qr,ans,mid,ansl,ansr))r = mid - 1;
            else l = mid + 1;
        }
        cout<<ansl<<' '<<ansr<<endl;
    }
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