#include<iostream>
#include<climits>
using namespace std;
#define int long long
const int MOD = 1004535809;
const int N = 1e7+10;
unsigned seed, mod; 
unsigned read() {
    seed ^= seed << 13; 
    seed ^= seed >> 5; 
    seed ^= seed << 7; 
    return seed % mod + 1; 
}

int a[N];
bool vis[N];
int n;
int ans;

signed main(){
    cin>>n>>seed>>mod;
    for(int i = 1;i <= n;i ++)a[i] = read();
    for(int k = n;k >= 1;k --){
        //从第 n 个开始 跳 k 的距离
        if(n % k != 0)continue;
        int sum = 0;
        int minn = INT_MAX;
        int pos = n;
        while(1){
            pos = (pos + k - 1) % n + 1;
            minn = min(minn,a[pos]);
            sum++;
            if(pos == n){
                int t = sum % MOD * minn % MOD;
                int s = 0;
                for(int j = k;j <= n;j += k){
                    if(!vis[j]){
                        vis[j] = true;
                        s ++;
                    }
                }
                ans += t % MOD * s % MOD;
                ans %= MOD;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}