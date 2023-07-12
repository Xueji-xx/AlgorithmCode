#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    int x,c;
    priority_queue<int,vector<int>,greater<int>> b;
    map<int,int> mp;
    b.push(0);
    for(int i = 1;i <= k;i ++){
        cin>>x>>c;
        if(c == 0){
            b.push(x+1);
        }
        else mp[x] = c;
    }
    sort(a.begin() + 1,a.end());
    int poi,ans = 0;
    for(int i = 1;i <= n;i ++){
        while(!b.empty() && b.top() <= a[i]){
            poi = b.top();
            b.pop();
        }
        ans += (a[i] - poi);
        if(mp.find(poi) == mp.end())continue;
        mp[poi]--;
        if(!mp[poi]){
            b.push(poi+1);
        }
    }
    if(ans & 1){
        cout<<"Pico"<<endl;
    }
    else cout<<"FuuFuu"<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}