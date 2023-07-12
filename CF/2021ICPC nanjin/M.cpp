#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
#define endl '\n'
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    int minn = INT_MAX;
    int sum = 0;
    int flag[3] = {0};
    if(n == 1){
        int x;
        cin>>x;
        cout<<x<<endl;
        return;
    }
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        if(a[i] < 0)flag[1] = 1;
        if(a[i] > 0)flag[2] = 1;
        minn = min(minn,abs(a[i]));
        sum += abs(a[i]);
    }
    if(flag[1] && flag[2])cout<<sum<<endl;
    else cout<<sum - 2*minn<<endl;
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