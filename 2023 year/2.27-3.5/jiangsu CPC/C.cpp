#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e6+50;
int a[N];
int dp[N];

unordered_map<int,int> mp;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,q,p;
    cin>>n>>q>>p;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    while(q--){
        deque<int> q;
        int x;
        cin>>x;
        if(mp.count(x)){
            cout<<mp[x]<<endl;
            continue;
        }
        if(x > p){
            cout<<"Noob"<<endl;
        }
        else{
            dp[0] = 0;
            q.push_back(0);
            vector<int> b;
            b.push_back(0);
            for(int i = x;i<= n;i += x){
                b.push_back(i);
            }
            b.push_back(n+1);
            for(int i = 1;i < b.size();i ++){
                while(!q.empty() && b[i] - b[q.front()] > p)q.pop_front();
                dp[i] = dp[q.front()] + a[b[i]];
                while(!q.empty() && dp[q.back()] <= dp[i])q.pop_back();
                q.push_back(i);
            }
            mp[x] = dp[b.size() - 1];
            cout<<mp[x]<<endl;
        }
    }
    return 0;
}