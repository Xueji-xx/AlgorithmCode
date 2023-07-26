#include <iostream>
using namespace std;
#define endl "\n"
#define int long long
void solve(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0;i < s.length();i ++){
        int res = 0;
        while(s[i] == s[i-1]){
            res ++;
            i ++;
        }
        ans += res;
    }
    cout << ans << endl;
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