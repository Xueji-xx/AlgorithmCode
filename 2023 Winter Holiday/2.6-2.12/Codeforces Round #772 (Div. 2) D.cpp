#include <iostream>
#include <map>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5+50;
int fac[N],sum[N];
const int mod = 1e9+7;
int a[N];
int ans;int n,p;
map<int,bool> mp;

int cal(int x){
    int res = 0;
    while(x){
        x /= 2;
        res++;
    }
    return res;
}

void solve(){
    fac[0] = fac[1] = 1;
    sum[0] = 1;
    sum[1] = 2;
    for(int i = 2;i <= 2e5;i ++){
        fac[i] = (fac[i-1] + fac[i-2]) % mod;
        sum[i] = (sum[i-1] + fac[i]) % mod;
    }
    cin>>n>>p;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        mp[a[i]] = true;
    }
    for(int i = 1;i <= n;i ++){
        int t = a[i];
        bool flag = false;
        while(t){
            if(t % 2)t /= 2;
            else if(!(t % 4)){
                t /= 4;
            }
            else break;
            if(mp.count(t)){
                flag = true;
                break;
            }
        }
        if(flag)continue;
        int len = cal(a[i]);
        if(p - len >= 0){
            ans = (ans + sum[p - len]) % mod;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while(t--)solve();
    return 0;
}