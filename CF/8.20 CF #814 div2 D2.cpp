#include<iostream>
#include<vector>
#include<map>
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
    map<int,pair<int,int> >mp;
    mp[0] = {0,0};
    for(int i = 1;i <= n;i ++){
        dp[i] = dp[i-1] + 1;
        if(mp.count(res[i])){
            dp[i] = min(dp[i],mp[res[i]].first + i - mp[res[i]].second - 1);
            if(mp[res[i]].first > dp[i]){
                mp[res[i]] = {dp[i],i};
            }
        }
        mp[res[i]] = {dp[i],i};
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