#include<iostream>
#include<string.h>
using namespace std;
const int N = 2e5+50;
#define int long long
int a[N];
int dp[N];
bool flag = false;

signed main(){
    int n,w;
    cin>>n>>w;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    int l = 0,r = N;
    int x = 0;
    if(!w){
        cout<<n+1<<endl;
        return 0;
    }
    while(l < r){
        memset(dp,0,sizeof dp);
        x = (l+r+1)/2;
        dp[0] = 0;
        for(int i = 1;i <= n;i ++){
            dp[i] = dp[i-1];
            if(i - x >= 0 && i + x <= n+1){
                dp[i] = max(dp[i],dp[i-x] + a[i]);
            }
        }
        if(dp[n] >= w){
            l = x;
            flag = true;
        }
        else r = x-1;
    }
    if(flag && l)cout<<l<<endl;
    else cout<<-1<<endl;
    return 0;
}