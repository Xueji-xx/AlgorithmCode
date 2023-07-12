#include <iostream>
using namespace std;
#define ll long long

void solve(){
    int n,q;
    cin>>n>>q;
    int a[n+10];
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    int ql,qr;
    while (q--) {
        cin>>ql>>qr;
    }
    ll s = 0, Xor = 0;
    for (int i = 1; i <= n; ++i) {
        s += a[i];
        Xor ^= a[i];
    }
    ll target = s - Xor;
    if (!target) {
        printf("1 1\n");
        return ;
    }
    ll cur_add = 0, cur_xor = 0;
    int resl = 1, resr = n;
    for (int l = 0, r = 0; l < n; ++l) {
        while (r + 1 <= n && cur_add - cur_xor < target) {
            cur_add += a[r+1];
            cur_xor ^= a[r+1];
            ++r;
        }
        if (cur_add - cur_xor < target) {
            break;
        }
        if (r - l < resr - resl + 1) {
            resl = l + 1;
            resr = r;
        }
        cur_add -= a[l+1];
        cur_xor ^= a[l+1];
    }
    cout<<resl<<' '<<resr<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}