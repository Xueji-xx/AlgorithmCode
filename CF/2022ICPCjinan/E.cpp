#include <iostream>
using namespace std;
#define int long long

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1,y = 0;
        return a;
    }
    int d = exgcd(b,a%b,x,y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int a = n / k,p = k - n % k;
    int b = n / k + 1,q = n % k;
    int x,y;
    int d = exgcd(a,b,x,y);
    if(n / 2 % d != 0){
        cout<<"No"<<endl;
        return;
    }
    x = x / d * (n / 2), y = y / d * (n / 2);

    int l = -1e9, r = 1e9;
    int l1 = r;
    while(l <= r) {
        int mid = l + r >> 1;
        if(x + mid * (b / d) >= 0) r = mid - 1, l1 = mid;
        else l = mid + 1;
    }

    l = -1e9, r = 1e9;
    int r1 = l;
    while(l <= r) {
        int mid = l + r >> 1;
        if(x + mid * (b / d) <= p) l = mid + 1, r1 = mid;
        else r = mid - 1;
    }

    l = -1e9, r = 1e9;
    int l2 = r;
    while(l <= r) {
        int mid = l + r >> 1;
        if(y - mid * (a / d) <= q) r = mid - 1, l2 = mid;
        else l = mid + 1;
    }

    l = -1e9, r = 1e9;
    int r2 = l;
    while(l <= r) {
        int mid = l + r >> 1;
        if(y - mid * (a / d) >= 0) l = mid + 1, r2 = mid;
        else r = mid - 1;
    }

    cout<<(max(l1, l2) <= min(r1, r2) ? "Yes" : "No")<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}