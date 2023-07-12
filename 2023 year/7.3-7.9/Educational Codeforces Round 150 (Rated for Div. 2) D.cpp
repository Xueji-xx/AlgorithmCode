#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
vector<PII> v;
const int M = 2050;
int dp[M][2];
int n;
int dfs(int i,int t){
    if(i == n)return 0;
    if(dp[i][t] != -1)return dp[i][t];
    if(!t){
        dp[i][t] = max(dfs(i+1,0),dfs(i+1,1));
        return dp[i][t];
    }
    int ans = 0;
    int x = v[i].first,y = v[i].second;
    for(int j = i + 1;j < n;j ++){
        if(v[j].first > y)break;
        int maxm = max(y,v[j].second);
        int k = j + 1;
        while(k < n && v[k].first <= maxm){
            k ++;
        }
        ans = max({ans,2 + dfs(k,0),2 + dfs(k,1)});
    }
    return dp[i][t] = ans;
}


int main(){
    int t;
    cin >> t;
    while(t --){
        v.clear();
        cin >> n;
        for(int i = 1;i <= n;i ++){
            int x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        sort(v.begin(),v.end());
        for(int i = 0;i < n;i ++){
            dp[i][0] = dp[i][1] = -1;
        }
        cout << n - max(dfs(0,0),dfs(0,1)) << endl;
    }
    return 0;
}