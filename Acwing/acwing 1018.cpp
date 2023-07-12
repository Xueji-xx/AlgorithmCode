#include<iostream>
#include<string.h>
using namespace std;
int map[150][150];
int dp[150][150];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cin>>map[i][j];
        }
    }
    memset(dp,0x3f,sizeof dp);
    dp[1][1] = map[1][1];
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + map[i][j];
        }
    }
    cout<<dp[n][n];
    return 0;
}