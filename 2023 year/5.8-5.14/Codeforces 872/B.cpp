#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5+50;
int a[N];

void solve(){
    int n,m;
    cin >> n >> m;
    if(n < m)swap(n,m);
    for(int i = 1;i <= n*m;i ++){
        cin >> a[i];
    }
    sort(a+1,a+1+n*m);
    int q = a[n*m],w = a[n*m-1],e = a[1],r = a[2];
    int x1 = q - e;
    int y1 = q - r;
    int ans1 = x1 * (n - 1) + y1 * (m - 1) + (n - 1) * (m - 1) * x1;
    int x2 = q - e;
    int y2 = w - e;
    int ans2 = x2 * (n - 1) + y2 * (m - 1) + (n - 1) * (m - 1) * x2;
    cout << max(ans1,ans2) << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
} 