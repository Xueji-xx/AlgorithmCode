#include <iostream>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n+10];
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    if(k > a[n]){
        cout<<0<<endl;
        return;
    }
    int ans = 99999999;
    for(int i = a[n] / k;i <= a[n];i ++){
        int minn = i;
        bool flag = true;
        for(int j = 1;j <= n;j ++){
            if(a[j] / k > i){
                flag = false;
                break;
            }
            int l = 1,r = k;
            while(l < r){
                int mid = l + r >> 1;
                if(a[j] / mid <= i) r = mid;
                else l = mid + 1;
            }
            minn = min(minn,a[j] / r);
        }
        if(flag)ans = min(ans,i - minn);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}