#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    map<int,int> mp;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+1+n);
    int ans = 0;
    int cnt = 1;
    for(int i = a[cnt];i <= a[n];i = a[++cnt]){
        if(mp[i+1] == 0){
            ans += mp[i];
            mp[i] = 0;
            continue;
        }
        int minn = 99999999;
        while(mp[i]){
            for(int j = i;mp[j];j ++){
                minn = min(minn,mp[j]);
            }
            for(int j = i;mp[j];j ++){
                mp[j] -= minn;
            }
            ans += minn;
            minn = 999999999;
        }
	}
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
