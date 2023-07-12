#include <iostream>
#include <map>
using namespace std;
#define int long long
map<int,int> mp;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int sum = 0;mp.clear();
    for(int i = 0;i < n;i ++){
        sum += s[i] - '0' - 1;
        if(sum == 0)ans ++;
        ans += mp[sum];
        mp[sum] ++;
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}