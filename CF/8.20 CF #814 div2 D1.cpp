#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    vector<int> dp(n+5);
    vector<int> res(n+5);
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        res[i] = res[i-1] ^ a[i];
    }
    for(int i = 1;i <= n;i ++){
        dp[i] = dp[i-1] + 1;
        for(int j = 0;j < i;j ++){
            if(res[i] == res[j]){
                dp[i] = min(dp[i],dp[j] + i - j - 1);
            }
        }
    }
    cout<<dp[n]<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}