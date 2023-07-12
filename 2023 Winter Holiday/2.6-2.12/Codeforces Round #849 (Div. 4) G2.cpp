#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a;
    for(int i = 0;i < n;i ++){
        int x;
        cin>>x;
        a.push_back({x + min(i + 1,n - i),x + i + 1});
    }
    sort(a.begin(),a.end());
    vector<int> sum;
    sum.push_back(0);
    for(int i = 0;i < n;i ++){
        sum.push_back(sum.back() + a[i].first);
    }
    int ans = 0;
    for(int i = 0;i < n;i ++){
        int c = k - a[i].second;
        int l = 0,r = n;
        int maxm = 0;
        while(l <= r){
            int mid = l + r >> 1;
            int price = sum[mid];
            int now = mid + 1;
            if(mid > i){
                price -= a[i].first;
                now--;
            }
            if(price <= c){
                maxm = max(now,maxm);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans = max(ans,maxm);
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}