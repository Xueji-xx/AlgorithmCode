#include<iostream>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    char g[n+10][m+10];
    int cnt1 = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin>>g[i][j];
            if(g[i][j] == '1'){
                cnt1++;
            }
        }
    }
    int maxm = -1;
    for(int i = 1;i <= n-1;i ++){
        for(int j = 1;j <= m-1;j ++){
            int cnt = 0;
            if(g[i][j] == '0')cnt++;
            if(g[i][j+1] == '0')cnt++;
            if(g[i+1][j+1] == '0')cnt++;
            if(g[i+1][j] == '0')cnt++;
            maxm = max(maxm,cnt);
        }
    }
    if(maxm >= 2)cout<<cnt1<<endl;
    else if(maxm == 1)cout<<max((int)0,cnt1-1)<<endl;
    else cout<<max((int)0,cnt1-2)<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}