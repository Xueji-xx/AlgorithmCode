#include <iostream>
using namespace std;

#define int long long

int f(int r,int x){
    string s = to_string(r);
    int res = 0;
    for(int L = 0;L <= 9;L ++){
        int R = min((long long)9,L + x);
        int now = 0;
        for(int i = 0;i <= s.size() - 1;i ++){
            for(int j = R;j >= L;j --){
                int t = now * 10 + j;
                for(int k = i + 1;k <= s.size() - 1;k ++){
                    t = t * 10 + L;
                }
                if(t <= r){
                    now = now * 10 + j;
                    break;
                }
            }
            res = max(res,now);
        }
    }
    return res;
}

void solve(){
    int l,r;
    cin >> l >> r;
    for(int i = 0;i <= 9;i ++){
        int x = f(r,i);
        if(x >= l){
            cout << x << endl;
            return;
        }
    }
    cout << -1 << endl;
}


signed main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}