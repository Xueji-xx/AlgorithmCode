#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    priority_queue<int,vector<int>,less<int>> q;
    int sum = 0;
    int cnt = 0;
    for(int i = m;i >= 2;i --){
        q.push(a[i]);
        sum += a[i];
        if(sum > 0){
            int x = q.top();
            q.pop();
            cnt ++;
            sum += (-x)*2;
        }
    }
    priority_queue<int,vector<int>,greater<int>> p;
    sum = 0;
    for(int i = m+1;i <= n;i ++){
        p.push(a[i]);
        sum += a[i];
        if(sum < 0){
            int x = p.top();
            p.pop();
            cnt++;
            sum += (-x) * 2;
        }
    }
    cout<<cnt<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}