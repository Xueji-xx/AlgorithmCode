#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define int long long
vector<int> v;

void dfs(int dep,long long res,int n){
    v.push_back(res);
    if(dep == 18)return;
    dfs(dep+1,res * 10,n);
    if(n < 3){
        for(int i = 1;i <= 9;i ++){
            dfs(dep+1,res * 10 + i,n + 1);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1;i <= 9;i ++){
        dfs(1,i,1);
    }
    v.push_back(1e18);
    sort(v.begin(),v.end());
    while(t--){
        int l,r;
        cin >> l >> r;
        cout << upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l) << endl;
    }
    return 0;
}