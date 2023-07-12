#include <iostream>
#include <math.h>
using namespace std;

#define int long long

void solve(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    bool flag = false;
    for(int i = pow(10,a-1);i < pow(10,a);i ++){
        int l = max(pow(10,b-1),pow(10,c-1) - i);
        int r = min(pow(10,c) - i - 1,pow(10,b) - 1);
        if(l > r)continue;
        int now = r - l + 1;
        if(now >= k){
            cout << i << " + " << l + k - 1 << " = " << i + l + k - 1 << endl;
            flag = true;
            break;
        }
        k -= now;
    }
    if(!flag)cout << -1 << endl;
}


signed main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}