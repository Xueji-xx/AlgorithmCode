#include <iostream>
using namespace std;
#define int long long
const int mod = 998244353;

int qmi(int a,int k,int p){
    int res = 1;
    while(k){
        if(k & 1)res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+10] = {0};
        int cnt,zero,one,ans;
        cnt = zero = one = ans = 0;
        for(int i = 1;i <= n;i ++){
            cin>>a[i];
            zero += (!a[i]);
        }
        for(int i = 1;i <= zero;i ++){
            one += a[i];
        }
        for(int i = 1;i <= one;i ++){
            ans = (ans + qmi(i*i%mod,mod-2,mod)) % mod;
        }
        ans = n * (n - 1) / 2 % mod * ans % mod;
        cout<<ans<<endl;
    }
    return 0;
}