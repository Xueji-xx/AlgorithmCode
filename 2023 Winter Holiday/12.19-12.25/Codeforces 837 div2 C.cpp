#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
const int N = 33333;
const int M = 1e5+5;

int pri[M];
bool vis[M];
int cnt;

void init(){
    for(int i = 2;i < N;i ++){
        if(!vis[i])pri[cnt++] = i;
        for(int j = 0;i * pri[j] < N;j ++){
            vis[pri[j] * i] = true;
            if(i % pri[j] == 0)break;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    map<int,int> mp;
    for(int& x:a){
        for(int i = 0;pri[i] * pri[i] <= x;i ++){
            int p = pri[i];
            if(x % p == 0){
                mp[p]++;
                while(x % p == 0)x /= p;
                if(mp[p] > 1){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
        if(x > 1)mp[x]++;
        if(mp[x] > 1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}