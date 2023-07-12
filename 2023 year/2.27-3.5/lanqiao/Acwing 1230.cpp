#include <iostream>
using namespace std;
const int N =  100500;
#define int long long

int a[N],sum[N],cnt[N];


signed main(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    int ans = 0;
    cnt[0] = 1;
    for(int i = 1;i <= n;i ++){
        ans += cnt[sum[i] % k];
        cnt[sum[i] % k]++;
    }
    cout<<ans<<endl;
    return 0;
}