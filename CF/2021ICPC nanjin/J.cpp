#include <iostream>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e6+500;
vector<int> pri;
vector<int> phi;
map<pair<int,int>,int> mp;
bool vis[N];
int cnt;
typedef pair<int,int> PII;

void prime(int n){
    vis[1] = true;
    for(int i = 2;i <= n;i ++){
        if(!vis[i])pri.push_back(i);
        for(int j = 0;pri[j] * i <= n;j ++){
            vis[pri[j] * i] = true;
            if(i % pri[j] == 0)break;
        }
    }
}

void get_phi(int d){
    for(int i = 0;i < pri.size();i ++){
        int now = pri[i];
        if(now > d)break;
        if(d % now == 0){
            phi.push_back(now);
            while(d % now == 0)d /= now;
        }
    }
    if(d > 1)phi.push_back(d);
}

int solve(int a,int d){
    PII p = {a,d};
    if(a == 1)return 0;
    else if(mp[p])return mp[p];
    int res = a - 1;
    for(auto v : phi){
        if(d % v == 0){
            int x = solve(a/v,d/v) + a % v;
            int y = solve(a/v+1,d/v) + v - a % v;
            res = min({res,x+1,y+1});
        }
    }
    mp[p] = res;
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    prime(500000);
    while(t--){
        int a,b;
        cin>>a>>b;
        mp.clear(),phi.clear();
        if(a > b)swap(a,b);
        if(a == 1){
            cout<<0<<endl;
            continue;
        }
        else if(b - a == 1){
            cout<<a - 1 <<endl;
            continue;
        }
        else if(a == b){
            cout<<1<<endl;
            continue;
        }
        get_phi(b-a);
        cout<<solve(a,b-a)<<endl;
    }
    return 0;
}