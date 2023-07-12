#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    bool flag = false;
    bool flag2 = false;
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum += a[i];
    }
    int ans = -99999999;
    for(int i = 1;i < n;i ++){
        if(a[i] == a[i+1]){
            if(a[i] == 1)ans = max(ans,sum-4);
            else ans = max(ans,sum+4);
        }
        else ans = max(sum,ans);
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}