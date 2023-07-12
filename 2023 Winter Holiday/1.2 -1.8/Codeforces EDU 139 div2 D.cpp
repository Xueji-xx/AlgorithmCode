#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e7+50;

int pri[N],cnt;
bool vis[N];
int p[N];

void init(){
    for(int i = 2;i <= N;i ++){
        if(!vis[i]){
            pri[cnt++] = i;
            p[i] = i;
        }
        for(int j = 0;i * pri[j] < N;j ++){
            vis[i * pri[j]] = 1;
            p[i*pri[j]] = pri[j];
            if(i % pri[j] == 0)break;
        }
    }
}

void solve(){
    int x,y;
    cin>>x>>y;
    int k = abs(x - y);
    //cout<<k<<endl;
    if(k == 1){
        cout<<-1<<endl;
        return;
    }
    if(__gcd(x,y) != 1){
        cout<<0<<endl;
        return;
    }
    int ans = 1e9;
    while(k > 1){
        ans = min(ans,p[k] - x % p[k]);
        int t = p[k];
        while(k % t == 0)k /= t;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    init();
    while(t--)solve();
    return 0;
}
