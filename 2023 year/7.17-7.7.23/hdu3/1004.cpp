#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
const int N = 1e5+50;
typedef pair<int,int> PII;
map<PII,int> mp;
PII a[N];


void Elysia(){
    int n;
    cin >> n;
    mp.clear();
    for(int i = 1;i <= 2 * n;i ++){
        cin >> a[i].first >> a[i].second;
        mp[a[i]] ++;
    }
    sort(a+1,a+2*n+1);
    vector<PII> ans;
    for(int i = 2;i <= n + 1;i ++){
        int dx = a[i].first - a[1].first;
        int dy = a[i].second - a[1].second;
        bool flag = false;
        vector<int> id;
        for(int j = 1;j <= 2*n;j ++){
            if(mp[a[j]]){
                mp[a[j]] --;
                mp[{a[j].first + dx,a[j].second + dy}] --;
                id.push_back(j);
                if(mp[a[j]] < 0 || mp[{a[j].first + dx,a[j].second + dy}] < 0){
                    for(auto k : id){
                        mp[a[k]] ++;
                        mp[{a[k].first + dx,a[k].second + dy}] ++;
                    }
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            ans.push_back({dx,dy});
            ans.push_back({-dx,-dy});
            for(int j = 1;j <= 2 * n;j ++){
                mp[a[j]] ++;
            }
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << ' ' << i.second << endl;
    }
}

signed main(){
    int t;
    cin >> t;
    while(t --){
        Elysia();
    }
    return 0;
}