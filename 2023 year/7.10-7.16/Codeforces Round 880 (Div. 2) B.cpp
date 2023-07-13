#include <iostream>
using namespace std;
    
#define int long long
    
signed main(){
    int t;
    cin >> t;
    while(t --){
        int n,k,g;
        cin >> n >> k >> g;
        int ans = (g - 1) / 2 * n;
        ans = min(ans / g, k);
        cout << ans * g << endl;
    }
    return 0;
}