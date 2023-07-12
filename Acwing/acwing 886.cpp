#include <iostream>
using namespace std;
#define int long long
const int N = 100010;
const int mod = 1e9+7;

int fact[N],infact[N];

int qmi(int a,int k,int q){
    int res = 1;
    while(k){
        if(k & 1)res = res * a % q;
        a = a * a % q;
        k >>= 1;
    }
    return res;
}

void init(){
    fact[0] = infact[0] = 1;
    for(int i = 1;i < N;i ++){
        fact[i] = fact[i-1] * i % mod;
        infact[i] = infact[i-1] * qmi(i,mod-2,mod) % mod;
    }
}

signed main(){
    init();
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<fact[a] * infact[a - b] % mod * infact[b] % mod<<endl;
    }
    return 0;
}