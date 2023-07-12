#include<iostream>
using namespace std;
#define int long long
const int mod = 100003;
int ai[200010];
int bi[200010];

int qmi(int a,int b,int k){
    int res = 1;
    while(b){
        if(b & 1)res = res * a % k;
        a = a * a % k;
        b >>= 1;
    }
    return res;
}

int C(int a,int b){
    if(b > a)return 0;
    return ai[a] * bi[b] % mod * bi[a - b] % mod;
}

int A(int a,int b){
    if(b > a)return 0;
    return ai[a] * bi[a - b] % mod;
}

signed main(){
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    ai[0] = 1;bi[0] = 1;
    for(int i = 1;i <= 2000;i ++){
        ai[i] = ai[i-1] * i % mod;
        bi[i] = bi[i-1] * qmi(i,mod-2,mod) % mod;
    }
    int ans = 0;
    for(int i = 0;i <= min(a,b);i ++){
        ans += C(b,i) * A(a,i) % mod * C(d,k - i) * A(a + c - i,k - i) % mod;
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}