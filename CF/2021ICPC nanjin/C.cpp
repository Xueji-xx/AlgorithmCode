#include<iostream>
using namespace std;
#define int long long
#define endl '\n'
const int pos = 2e6+50;
const int N = 1e7+50;
int a[N],cnt[N];
int ans;
int val[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i = 0;i < n;i ++){
        cin>>a[i];
        cnt[a[i]+pos]++;
        ans = max(ans,cnt[a[i]+pos]);
    }
    if(k != 0){
        for(int i = 0;i < n;i ++){
            val[a[i]+pos]--;
            if(val[a[i]+pos] < 0)val[a[i]+pos] = 0;
            val[a[i]+k+pos]++;
            ans = max(ans,val[a[i] + k + pos] + cnt[a[i] + k + pos]);
        }
    }
    cout<<ans<<endl;
    return 0;
}