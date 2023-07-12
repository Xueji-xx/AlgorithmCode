#include<iostream>
using namespace std;
#define int long long



void solve(){
    int n;
    cin>>n;
    if(n == 1){
        int x;
        cin>>x;
        cout<<0<<endl;
        return;
    }
    int a[n+5];
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    if(a[1] == 1){
        for(int i = 1;i <= n;i ++)ans += a[i]-1;
        cout<<ans<<endl;
    }
    else{
        for(int i = 2;i <= n;i ++){
            int x = 2 * a[1];
            if(a[i] >= x){
                int y = a[i] / x;
                ans += y;
            }
        }
        cout<<ans<<endl;
    } 
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}