#include<iostream>
using namespace std;
int dp[1500][1500];

int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i] == b[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    system("pause");
    return 0;
}