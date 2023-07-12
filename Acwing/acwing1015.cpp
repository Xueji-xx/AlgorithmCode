#include<iostream>
#include<string.h>
using namespace std;
int map[150][150];
int dp[150][150];

void solve(){
    int r,c;
    memset(map,0,sizeof map);
    cin>>r>>c;
    for(int i = 1;i <= r;i ++){
        for(int j = 1;j <+ c;j ++){
            cin>>map[i][j];
        }
    }
    dp[1][1] = map[1][1];
    for(int i = 1;i <= r;i ++){
        for(int j = 1;j <= c;j ++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + map[i][j];
        }
    }
    cout<<dp[r][c]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}