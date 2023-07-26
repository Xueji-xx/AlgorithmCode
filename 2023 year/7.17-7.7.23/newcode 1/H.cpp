#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0;i < n;i ++)cin >> a[i].first;
    for(int i = 0;i < n;i ++)cin >> a[i].second;

    ll ans = 0,sum = 0;
    vector<PII> T,tmp; 
    for(auto[x , y] : a){
        sum += abs(x - y);
        if(x < y)tmp.push_back({x,y});
        else if(x > y)T.push_back({y,x});
    }
    sort(tmp.begin(),tmp.end());
    ll r = -1e18;
    vector<ll> X,Y,len;
    for(auto x : tmp){
        if(x.second <= r)continue;
        r = x.second;
        X.push_back(x.first);
        Y.push_back(x.second);
        len.push_back(x.second - x.first);
    }
    auto query = [&](ll x,ll y){
        ll n = X.size(), res = 0;
        ll l = upper_bound(X.begin(), X.end(), x) - X.begin();
        ll r = lower_bound(Y.begin(), Y.end(), y) - Y.begin();

        if(l > 0)res = max(res,min(y,Y[l-1]) - x);
        if(r < n)res = max(res,y - max(x,X[r]));
        if(r > l)res = max(res,*max_element(len.begin() + l,len.begin() + r));
        return res;
    };

    for(auto x : T){
        ans = max(ans, query(x.first, x.second));
    }
    cout << sum - 2 * ans << endl;
    return 0;
}