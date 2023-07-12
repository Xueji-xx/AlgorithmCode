#include <iostream>
using namespace std;
const int N = 5010;
int a[N],dp[N],ans1,ans2,n,f[N];

int main(){
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++){
        dp[i] = 1;
        for(int j = 1;j < i;j ++){
            if(a[i] < a[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans1 = max(ans1,dp[i]);
    }
    for(int i = 1;i <= n;i ++){
        if(dp[i] == 1)f[i] = 1;
        for(int j = 1;j < i;j ++){
            if(dp[i] == dp[j] + 1 && a[i] < a[j])f[i] += f[j];
            else if(dp[i] == dp[j] && a[i] == a[j])f[i] = 0;
        }
        if(dp[i] == ans1)ans2 += f[i];
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}