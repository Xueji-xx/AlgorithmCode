#include<iostream>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n+5];
    int maxm[200] = {0};
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 0;i < k;i ++){
        int x = i;
        while(x < n){
            maxm[i] = max(maxm[i],a[x]);
            x += k;
        }
    }
    int sum = 0;
    for(int i = 0;i < k;i ++)sum += maxm[i];
    cout<<sum<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}