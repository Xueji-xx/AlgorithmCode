#include<iostream>
#include<string.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
const int N = 600;

int dp[N][N],ans[N][N];


void solve(){
    int n,m;
    cin>>n>>m;
    memset(dp,0,sizeof dp);
    memset(ans,0,sizeof ans);
    int a[N];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    if(n & 1){//奇数长度的括号序列不匹配
        cout<<0<<endl;
        return;
    }
    for(int i = 0;i <= n;i ++)ans[i+1][i] = 1;
    for(int len = 2;len <= n;len += 2){//奇数长度的括号序列一定不匹配，故len+=2
        for(int l = 1;l + len - 1 <= n;l++){
            int r = l + len - 1;
            if(a[l] >= 0 && a[r] <= 0){
                int b = 0;
                if(a[l] == 0 && a[r] == 0)b = m;//两端都是0，说明有m个匹配的方法
                else if(a[l] == 0 || a[r] == 0)b = 1;//有一端确定，说明只有一种匹配方法
                else if(a[l] == -1*a[r])b = 1;//两端匹配成功，只有一种匹配方法
                else b = 0;//没有匹配成功
                dp[l][r] = 1ll*ans[l+1][r-1]*b%mod;
            }
            for(int i = l;i <= r;i += 2){
                ans[l][r] = (ans[l][r] + 1ll*ans[l][i-1]*dp[i][r])%mod;
            }
        }
    }
    cout<<ans[1][n]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}