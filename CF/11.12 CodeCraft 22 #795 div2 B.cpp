#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
int n;

void solve(){
    cin >> n ;
    vector<ll> a(n + 1 , 0) ;
    for(int i = 1;i <= n;i ++)cin >> a[i] ;
    
    map<ll , deque<ll>> mp ;
    for(int i = 1;i <= n;i ++){
        mp[a[i]].push_back(i) ;
    }
    
    for(int i = 1;i <= n;i ++){
        if(mp[a[i]].size() == 1){
            cout << "-1\n" ; 
            return ;
        }
    }
    
    for(auto &x : mp){
        x.second.push_back(x.second.front()) ;
        x.second.pop_front() ;
    }
    
    for(int i = 1;i <= n;i ++){
        ll x = mp[a[i]].front() ;
        mp[a[i]].pop_front() ;
        cout << x << " \n"[i == n] ;
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}