#include <iostream>
using namespace std;

const int N = 1e5+50;
int f[N][10];
//fij 表示前 i 家店铺，第 i 家拿或不拿的方案数

void solve(){
    int n;
    cin >> n;
    int a[n+10] = {0};
    for(int i = 1;i <= n;i ++)cin >> a[i];
    for(int i = 1;i <= n;i ++){
        f[i][0] = max(f[i-1][1],f[i-1][0]);
        f[i][1] = f[i-1][0] + a[i];
    }
    cout << max(f[n][0],f[n][1]) << endl;
}

int main(){
    f[0][0] = 0;
    f[0][1] = -9666666;
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}