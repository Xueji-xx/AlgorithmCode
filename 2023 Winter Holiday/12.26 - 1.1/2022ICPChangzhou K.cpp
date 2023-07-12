#include <iostream>
using namespace std;
#define int long long
const int N = 1e6+50;
int son[N][26];
int idx;
int cnt[N][26];

int n,q,dp[27][27],res;

void add(string s){
    int p = 0;
    for(int i = 0;i < s.length();i ++){
        int u = s[i] - 'a';
        if(!son[p][u]){
            son[p][u] = idx++;
        }
        for(int vec = 0;vec < 26;vec ++){
            if(vec == u)continue;
            if(son[p][vec])dp[u][vec] += cnt[p][vec];
        }
        cnt[p][u]++;
        p = son[p][u];
    }
    for(int v = 0;v < 26;v ++){
        if(son[p][v])res += cnt[p][v];
    }
}

signed main(){
    son[0][0] = son[0][1] = 0;
    idx = 1;
    cin >> n >> q;
    for(int i = 1;i <= n;i ++){
        string s;
        cin>>s;
        add(s);
    }
    while(q--){
        string s;
        cin>>s;
        int ans = res;
        for(int i = 0;i < 26;i ++){
            for(int j = i + 1;j < 26;j ++){
                ans += dp[s[i] - 'a'][s[j] - 'a'];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}