#include <iostream>
using namespace std;

const int N = 2e5+50;
const int mod = 998244353;
int f[N],t[N];
int ans[N];

int main(){
    int n,k;
    cin>>n>>k;
    t[0] = 1;
    for(int j = 1;j * (j +1) <= 2 * n;j ++){
        for(int i = 1;i <= n;i ++){
            if(i >= k + j - 1)f[i] = (f[i - (k + j - 1)] + t[i - (k + j - 1)]) % mod;
        }
        for(int i = 0;i <= n;i ++){
            ans[i] = (ans[i] + f[i]) % mod;
            t[i] = f[i];
            f[i] = 0;
        }
    }
    for(int i = 1;i <= n;i ++)cout<<ans[i]<<' ';
    return 0;
}