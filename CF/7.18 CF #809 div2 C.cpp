#include<iostream>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    int a[n+50] = {0};
    for(int i = 1;i <= n;i ++)cin>>a[i];
    ll sum1[n+50] = {0};
    ll sum2[n+50] = {0};
    int cnt1 = 0,cnt2 = 0;
    for(int i = 2;i < n;i += 2){
        if(a[i] > a[i-1] && a[i] >a[i+1]){
            cnt1++;
            sum1[cnt1] = sum1[cnt1-1];
            continue;
        }
        cnt1++;
        sum1[cnt1] = sum1[cnt1-1] + (max(a[i+1] , a[i-1]) + 1 - a[i]);
    }
    if(n == 3){
        cout<<sum1[cnt1]<<endl;
        return;
    }
    cnt2 = cnt1+1;
    for(int i = n - 1;i > 1;i -= 2){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            cnt2--;
            sum2[cnt2] = sum2[cnt2+1];
            continue;
        }
        cnt2--;
        sum2[cnt2] = sum2[cnt2+1] + max(a[i+1],a[i-1])+1-a[i];
    }
    ll ans = min(sum1[cnt1],sum2[1]);
    if(n % 2 == 1){
        cout<<ans<<endl;
        return;
    }
    for(int i = 1;i < cnt1;i ++){
        ans = min(ans,sum1[i]+sum2[i+1]);
    }
    cout<<ans<<endl;
}  

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}