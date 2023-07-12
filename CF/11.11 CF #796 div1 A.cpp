#include <iostream>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n+10] = {0};
        int sum[n+10] = {0};
        for(int i = 1;i <= n;i ++){
            cin>>a[i];
            sum[i] = sum[i-1] + a[i];
        }
        if(k <= n){
            int ans = 0;
            for(int i = k;i <= n;i ++){
                ans = max(ans,sum[i] - sum[i-k]);
            }
            cout<<ans + k * (k - 1) / 2<<endl;
        }
        else{
            int ans = sum[n];
            cout<<ans - n * (n + 1 - k * 2)/ 2<<endl;
        }
    }
    return 0;
}