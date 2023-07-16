#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

int cal(vector<int> &b){
    int len = b.size();
    int res = 0;
    int sum = 0;
    for(int i = 0;i < len;i ++){
        res = res + b[i] * i - sum;
        sum += b[i];
    }
    return res;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m,vector<int>());
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < m;j ++){
            int x;
            cin >> x;
            a[j].push_back(x);
        }
    }
    int ans = 0;
    for(int j = 0;j < m;j ++){
        sort(a[j].begin(),a[j].end());
        ans += cal(a[j]);
    }
    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}