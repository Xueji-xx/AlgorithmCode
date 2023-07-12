#include <iostream>
#include <map>
using namespace std;
#define int long long
const int mod = 998244353;
const int M = (mod + 1)/2;

void solve(){
    int n;
    cin>>n;
    int sum = 0;
    map<int,int> s;
    int cnt = 1,X = 1;
    while(n --){
        int op;int x;
        cin>>op;
        if(op != 3)cin>>x;
        if(op == 1){
            s[x + sum] = (s[x + sum] + X) % mod;
        }
        else if(op == 2)sum += x;
        else if(sum <= 2e5){//没有扣完
            if(sum == 0){// 没有扣血，只有重复
                cnt = cnt * 2 % mod;
                X = X * M % mod;
            }
            else{//前面存在扣血
                for(int i = sum + 2e5;i > sum;i --){
                    s[i+sum] = (s[i+sum] + s[i]) % mod;
                }
                sum *= 2;
            }
        }
    }
    int ans = 0;
    for(auto i : s){
        if(i.first > sum)ans += i.second;
    }
    ans = ans % mod * cnt % mod;
    cout<<ans;
}

signed main(){
        solve();
    return 0;
}