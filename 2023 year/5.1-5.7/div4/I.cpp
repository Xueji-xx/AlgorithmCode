#include <iostream>
using namespace std;
#define int long long
const int p = 998244353;

int qmi(int a,int b){
    int res = 1;
    while(b){
        if(b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int inv(int x){
    return qmi(x,p-2);
}

signed main(){
    int n,m;
    cin >> n >> m;
    int res= 1;
    for(int x = 1;x <= m;x ++){
        cout << qmi((m - x) * inv(m - 1) % p,n) << ' ';
    }
    return 0;
}