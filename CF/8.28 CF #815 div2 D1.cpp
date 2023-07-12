#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    vector<int> dp(n+5,1);
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n; i++){
        for(int j = i + 1;j <= min(n,i+400);j ++){
            if((a[i] ^ (j - 1)) < (a[j] ^ (i - 1)))dp[j] = max(dp[j],dp[i] + 1);
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}