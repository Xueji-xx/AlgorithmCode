#include<iostream>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    int a[n+10] = {0};
    int dp[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = m;j >= a[i];j --){
            dp[j] += dp[j - v[i]];
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}