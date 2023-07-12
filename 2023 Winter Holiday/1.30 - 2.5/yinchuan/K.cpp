#include <iostream>
#include <unordered_map>
using namespace std;
#define int long long

const int N = 1e5+50;
const int mod = 10000000000123207;
unordered_map<int,int> mp(N*50);
unordered_map<int,int> vis(N*50);

int k = 131;
string s[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        cin>>s[i];
        int pre = 0;
        for(auto ch : s[i]){
            pre = (pre * k + ch) % mod; 
            mp[pre]++;
        }
    }
    int res = 0;
    for(int i =1;i <= n;i ++){
        int pre = 0;
        for(auto ch:s[i]){
            pre = (pre * k + ch) % mod;
            mp[pre]--;
            if(!mp[pre])mp.erase(pre);
            if(!mp.count(pre))break;
        }
        int cnt = vis[pre];
        res = res - cnt + 1;
        cout<<res<<'\n';
        pre = 0;
        for(auto ch : s[i]){
            pre = (pre * k + ch) % mod;
            vis[pre]++;
            vis[pre] -= cnt;
        }
    }
    return 0;
}