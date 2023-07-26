#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define int long long
const int mod = 998244353;
 
int p[50];
 
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
 
signed main() {
    int n, m;
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 0; i <= 31; i ++) p[i] = pow(2, i);
    for (int i = 0; i <= 31; i ++) {
        if (!l && p[i] - 1 >= n ) l = i;
        if (p[i] - 1 <= m + n) r = i;
    }
    int ans = 1;
    for (int i = l; i < r; i ++)
        ans = (ans * power(((p[i] - 1) * power(p[i], mod - 2)) % mod, p[i])) % mod;
    if(n >= p[l-1] - 1 && n+m <= p[l] - 1)
        ans = (ans * power(((p[l - 1] - 1) * power(p[l - 1], mod - 2)) % mod, m)) % mod;
    else{
        ans = (ans * power(((p[l - 1] - 1) * power(p[l - 1], mod - 2)) % mod, p[l] - 1 - n)) % mod;
        ans = (ans * power(((p[r] - 1) * power(p[r], mod - 2)) % mod, m + n - p[r] + 1)) % mod;     
    }
    cout << ans << endl;
    return 0;
}