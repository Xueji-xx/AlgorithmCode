#include <iostream>
using namespace std;

#define int long long


signed main(){
    int n;
    cin >> n;
    int a[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            for(int k = 1;k <= n;k ++){
                ans = max(ans,a[i] | a[j] | a[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}