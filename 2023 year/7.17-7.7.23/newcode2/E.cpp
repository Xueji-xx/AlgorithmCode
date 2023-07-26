#include <iostream>
#include <math.h>
using namespace std;

#define int long long
#define endl "\n"
int n;

bool check(int x){
    int t = n;
    int cnt1 = 0;
    while(t){
        cnt1 ++;
        t /= 10;
    }
    t = x;
    int cnt2 = 0;
    while(t){
        cnt2 ++;
        t /= 10;
    }
    if(cnt2 - cnt1 < 0)return false;
    x /= pow(10,cnt2 - cnt1);
    if(x == n)return true;
    else return false;
}

void solve(){
    cin >> n;
    int t = n;
    while(t < (long long)1e18){
        int x = sqrt(t);
        for(int i = (x - 3 > 0? x - 3 : 0);i <= x + 3;i ++){
            if(check(i*i)){
                cout << i << endl;
                // cout << (long long)i * i <<'*'<< endl;
                return;
            }
        }
        t = t * 10;
    }
    cout << -1 << endl;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}