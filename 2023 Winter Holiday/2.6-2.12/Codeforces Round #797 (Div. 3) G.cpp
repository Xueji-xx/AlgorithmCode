#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'
map<int,int> mp;

void add(int i,int x){
    mp[i] = x;
    auto t = mp.find(i);
    if(t != mp.begin() && prev(t)->second <= x){
        mp.erase(t);
        return;
    }
    while(next(t) != mp.end() && next(t) ->second >= x){
        mp.erase(next(t));
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    mp.clear();
    vector<int> a(n+10);
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++)add(i,a[i]);
    int pos,x;
    for(int i = 1;i <= k;i ++){
        cin>>pos>>x;
        a[pos] -= x;
        add(pos,a[pos]);
        cout<<mp.size()<<' ';
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}