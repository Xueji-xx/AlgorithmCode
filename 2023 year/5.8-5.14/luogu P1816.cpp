#include <iostream>
#include <cmath>
using namespace std;

#define int long long
#define endl '\n'

const int N = 1e5+50;
int a[N];
int f[N][20];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 0;i <= n;i ++){
        f[i][0] = a[i];
    }
    for(int j = 1;j <= 20;j ++){
        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
            f[i][j] = min(f[i][j-1],f[i + (1 << (j - 1))][j - 1]);
        }
    }
    while(q --){
        int l,r;
        cin >> l >> r;
        int len = r - l + 1;
        int k = log2(len);
        
        cout << min(f[l][k],f[r - (1 << k)+1][k]) << ' ';
    }
    return 0;
}