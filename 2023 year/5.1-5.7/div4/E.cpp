#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define endl '\n'
const int N = 1e6+50;
const int mod = 998244353;
#define int long long
typedef pair<int,int> PII;
PII a[N];
int d[N];
vector<int> s;
map<int,int> mp;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int a,b;
        cin >> a >> b;
        d[a] ++;
        d[b] ++;
    }
    for(int i = 1;i <= n;i ++){
        if(!mp[d[i]])s.push_back(d[i]);
        mp[d[i]] ++;
    }
    int ans = 0;
    for(int i = 0;i < s.size();i ++){
        for(int j = i + 1;j < s.size();j ++){
            int x = (s[i] ^ s[j]) * (s[i] & s[j]) * (s[i] | s[j]) * mp[s[i]] * mp[s[j]];
            ans += x;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}