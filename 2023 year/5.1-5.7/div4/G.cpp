#include <iostream>
using namespace std;

#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n+10] = {0};
    int x;
    cin >> x;
    a[1] = x;
    for(int i = 2;i <= n;i ++){
        cin >> x;
        a[i] = x + a[i-1];
    }
    if(a[n] < 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i ++){
        if(a[i] != 0){
            if(a[i] < 0){
                cout << -1 << endl;
                return 0;
            }
            break;
        }
    }
    int maxm = 0;
    int res = 0;
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        maxm = max(maxm,a[i]);
        res += a[i];
        ans ++;
        if(res < 0){
            int time = (-res + maxm - 1) / maxm;
            ans += time;
            res += time * maxm;
        }
    }
    cout << ans << endl;
    return 0;
}