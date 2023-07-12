#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define int long long
const int mod=1e9+7;
int c[1005][1005];
void init(){
    c[1][0] = c[1][1] = 1;
    for(int i = 2;i <= 1000;i ++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1;j < i;j ++){
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
}

bool cmp(int x,int y){
    return x > y;
}

void solve(){
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    int a[n+10] = {0};
    for(int i = 0;i < n;i ++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a,a+n,cmp);
    int ans = 1;
    int t = k;
    int i = 0;
    while(i < k){
        if(i + mp[a[i]] >= k){
            ans = ans * c[mp[a[i]]][t] % mod;
            break;
        }
        else{
            t -= mp[a[i]];
            i += mp[a[i]];
        }
    }
    cout<<ans%mod<<endl;
}

signed main(){
    init();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}