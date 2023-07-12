#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

const int N = 1e9+7;
const int M = 2e5+50;
int a[M];
int b[M];
int cnt[M];

void solve(){
    int n;
    cin >> n;
    int a[n+10] = {0};
    int b[n+10] = {0};
    int cnt[n+10] = {0};
    for(int i = 1;i <= n;i ++)cin >> a[i];
    for(int i = 1;i <= n;i ++)cin >> b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    /*for(int i = 1;i <= n;i ++)cout << b[i] << ' ';
    cout << endl;*/
    for(int i = n;i >= 1;i --){
        if(a[i] > b[n])cnt[n] ++;
        else break;
    }
    for(int i = n - 1;i >= 1;i --){
        cnt[i] = cnt[i+1]-(n - i);
        for(int j = n - cnt[i+1];j >= 1;j --){
            if(a[j] > b[i])cnt[i] ++;
            else break;
        }
        cnt[i] %= N;
    }
    int ans = 1;
    for(int i = 1;i <= n;i ++){
        ans = ans * cnt[i] % N;
    }
    cout << ans % N << endl;
    /*for(int i = 1;i <= n;i ++)cout << cnt[i] << ' ';
    cout << endl;*/
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