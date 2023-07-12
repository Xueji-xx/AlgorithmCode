#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define int long long

signed main(){
    int n,k;
    cin >> n >> k;
    int a[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = n;i >= 1;i --){
        a[i] += a[i+1];
    }
    sort(a+2,a+1+n,greater<int>());
    int ans = 0;
    for(int i = 1;i <= k;i ++)ans += a[i];
    cout << ans << endl;
    return 0;
}