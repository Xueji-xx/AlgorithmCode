#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define int long long
vector<int> f(50);
map<int,int> mp;
bool flag2 = false;
void init(){
    if(flag2)return ;
    flag2 = true;
    f[0] = f[1] = 1;
    mp[1] = 0,mp[2] = 1;
    int sum = 2;
    for(int i = 2;i < 50;i ++){
        f[i] = f[i-1] + f[i-2];
        sum += f[i];
        mp[sum] = i;
    }
}

void solve(){
    init();
    int n;
    cin>>n;
    vector<int> c(n);
    int sum = 0;
    priority_queue<int> que;
    for(auto &x : c){
        cin>>x;
        sum += x;
        que.push(x);
    }
    if(!mp.count(sum)){
        cout<<"NO"<<endl;
        return;
    }
    int la = 0;
    bool flag = true;
    for(int i = mp[sum];i >= 0;i --){
        if(que.empty()){
            flag = false;
            break;
        }
        int t = que.top();
        que.pop();
        if(t < f[i]){
            flag = false;
            break;
        }
        if(la)que.push(la);
        la = t - f[i];
    }
    cout<<(flag ? "YES" : "NO")<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}