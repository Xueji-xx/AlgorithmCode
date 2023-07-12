#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<set>
using namespace std;
const int N = 2e5+10;
#define ll long long
struct node{
    ll s;
    ll e;
}a[N];
deque<ll> q[N];
bool cmp(node a,node b){
    return a.s < b.s;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i ++)cin>>a[i].s>>a[i].e;
    sort(a+1,a+n+1,cmp);
    set<int> s;//下标
    set<pair<int,int>> s2;//时间长度，下标
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;//结束时间，下标
    for(int i = 1;i <= m;i ++)s.insert(i),q[i].clear();


    //入队操作
    for(int i = 1;i <= n;i ++){
        while(p.size() && p.top().first <= a[i].s){
            int id = p.top().second;
            p.pop();
            s2.erase(make_pair(q[id].size(),id));
            q[id].pop_front();
            if(q[id].empty())s.insert(id);
            else{
                s2.insert({q[id].size(),id});
                p.push({q[id].front(),id});
            }
        }
        if(s.size() > 0){
            int id = *s.begin();
            s.erase(id);
            q[id].push_back(a[i].s+a[i].e);
            s2.insert({1,id});
            p.push({a[i].s+a[i].e,id});
        }
        else{
            int id = s2.begin()->second;
            int len = s2.begin()->first;
            s2.erase(s2.begin());
            q[id].push_back(max(q[id].back(),a[i].s) + a[i].e);
            s2.insert({len+1,id});
        }
    }
    ll ans = 0;
    for(auto id : s2)ans = max(ans,q[id.second].back());
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}