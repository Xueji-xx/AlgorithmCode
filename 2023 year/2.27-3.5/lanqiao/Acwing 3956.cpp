#include <iostream>
using namespace std;
#define int long long
const int N = 1e5+50;
int a[N],sum[N];

signed main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    if(sum[n] % 3 != 0 || n < 3)cout<<0;
    else{
        int ans = 0;
        int cnt = 0;
        int ave = sum[n] / 3;
        for(int i = 1;i < n;i ++){
            if(sum[i] == ave*2)ans += cnt;
            if(sum[i] == ave)cnt++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}