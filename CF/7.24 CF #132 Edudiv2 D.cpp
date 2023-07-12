#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i = 0;i < m;i ++)scanf("%d",&a[i]);
    vector<vector<int>> dp(m,vector<int>(19));
    //RMQ
    for(int i = 0;i < m;i ++)dp[i][0] = n-a[i];
    for(int i = 1;i < 19;i ++){
        for(int j = 0;j < m;j ++){
            dp[j][i] = dp[j][i-1];
            if((j + (1 << (i-1))) < m)dp[j][i] = min(dp[j][i-1],dp[(j+(1<<(i-1)))][i-1]);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int sx,sy,fx,fy,k;
        scanf("%d %d %d %d %d",&sx,&sy,&fx,&fy,&k);
        sx = n-sx;sy--;fx = n-fx;fy--;
        if(((fx-sx) % k)|| ((fy-sy) % k)){
            cout<<"NO"<<endl;
            continue;
        }
        sx %= k;
        if(sy > fy)swap(sy,fy); 
        int p = log(fy-sy+1)/log(2);
        int minn = min(dp[sy][p],dp[fy-(1<<p)+1][p]);
        if(minn <=sx)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}

int main(){
    solve();
    system("pause");
    return 0;
}