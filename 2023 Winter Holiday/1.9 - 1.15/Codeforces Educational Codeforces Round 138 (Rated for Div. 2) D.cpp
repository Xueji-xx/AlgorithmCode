#include <iostream>
using namespace std;
#define int long long
const int N = 3e5+50;
const int mod = 998244353;

int pri[N];
bool vis[N];
int cnt;

void init(int n){
    for(int i = 2;i <= n;i ++){
        if(vis[i])continue;
        for(int j = i;j <= n / i;j ++){
            vis[i * j] = 1;
        }
    }
    pri[0] = 1;
    for(int i = 1;i <= n;i ++){
        pri[i] = pri[i-1];
        if(!vis[i])pri[i] = pri[i] * i;
    }
}

signed main(){
    long long n,m;
    cin>>n>>m;
    init(n);
    long long res = 1,ans = 0;
    for(int i = 1;i <= n;i ++){
        if(pri[i] > m)break;
        res = (res * ((m / pri[i]) % mod)) % mod;
        ans = (ans + res) % mod;
    }
    long long tot = 0,t1 = 1;
    for(int i = 1;i <= n;i ++){
        t1 = (t1 * (m % mod))% mod;
        tot = (tot + t1) % mod; 
    }
    cout<<(tot - ans + mod) % mod<<endl;
    return 0;
}