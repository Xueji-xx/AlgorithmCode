#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


void solve(){
    int n;
    string s;
    cin>>n>>s;
    map<int,vector<int>> pos;
    for(int i = 0;i < n;i ++){
        pos[s[i] - 'a'].push_back(i);
    }
    string t;
    vector<pair<int,int>> p;
    for(int i = 0;i < 26;i ++){
        if(!pos.count(i))p.push_back({0,i});
        else p.push_back({pos[i].size(),i});
    }
    sort(p.begin(),p.end(),greater<pair<int,int>>());
    int ans = n + 1;
    int f = -1;
    for(int i = 1;i <= 26;i ++){
        if(n % i)continue;
        int cnt = n / i;
        int res = 0;
        for(int j = 0;j < i;j ++){
            if(p[j].first > cnt){
                res += p[j].first - cnt;
            }
        }
        for(int j = i;j < 26;j ++){
            res += p[j].first;
        }
        if(res < ans){
            ans = res;
            f = i;
        }
    }
    cout<<ans<<endl;
    vector<int> a1;
    vector<int> a2;
    t = s;
    int cnt = n / f;
    for(int j = 0; j < f; j++){
        if (p[j].first > cnt){
            for(int k = 0; k < p[j].first - cnt; k++)
                a1.push_back(pos[p[j].second][k]);
        }
        if (p[j].first < cnt){
            for(int k = 0; k < cnt - p[j].first; k++)
                a2.push_back(p[j].second);
        }
    }
    for(int j = f; j < 26; j++){
        if (pos.count(p[j].second)){
            for(auto x : pos[p[j].second])
                a1.push_back(x);
        }
    }
    for(int i = 0; i < ans; i++)
        s[a1[i]] = char(a2[i] + 'a');
    cout << s << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}