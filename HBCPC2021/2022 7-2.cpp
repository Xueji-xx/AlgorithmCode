#include<iostream>
#include<cmath>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e7+50;
const int MOD = 1e9+7;
int sum[N];

inline int f(int n){
    //cout<<(int)sqrt(n)<<' '<<(int)(n/(sqrt(n) + 1))<<endl;
    return (int)floor(sqrt(n))%MOD + (int)floor(n / (floor(sqrt(n)) + 1))%MOD;
}

void solve(){
    int n;
    cin>>n;
    int ans = 0;
    if(n < N)cout<<sum[n]%MOD<<endl;
    else {
        ans = sum[N];
        for(int i = N;i <= n;i ++){
            ans += f(i)%MOD;
            ans %= MOD;
        }
        cout<<ans%MOD<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i = 1;i <= N;i ++){
        sum[i] = f(i)%MOD + sum[i-1]%MOD;
        sum[i] %= MOD;
    }
    while(t--)solve();
    return 0;
}