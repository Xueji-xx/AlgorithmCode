#include <iostream>
using namespace std;
#define int long long
#define endl '\n'
const int p = 1e9+7;
const int N = 1000010;
int fact[N],infact[N];

inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}

inline int qmi(int a,int b){
    int res = 1;
    while(b){
        if(b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void init(){
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ ){
        fact[i] = fact[i - 1] * i % p;
        infact[i] = infact[i - 1] * qmi(i, p - 2) % p;
    }
}

inline int C(int n,int m){
    if(m < 0 || m > n)return 0;
    return fact[n] * infact[n-m] % p * infact[m] % p;
}

void solve(){
    int n,k;
    n = read();
    k = read();
    int ans = 0;
    if(!k){
        cout<<qmi(3,n)<<endl;   
        return;
    }
    
    for(int i = 1;i <= k;i ++){
        if(i * 2 <= n)ans += qmi(3,n-i*2) % p * C(k-1,i-1) % p * C(n-k,i) % p;
        if(i * 2 - 1 <= n)ans += qmi(3,n-i*2+1) % p * C(k-1,i-1) % p * C(n-k,i-1)%p;
        ans %= p;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}