#include <iostream>
using namespace std;
#define int long long
const int N = 250;
int f[N][N];//表示和为 i ，最大值为 j 的方案数
//f[i][j] = f[i]
const int mod = 1e9+7;

signed main(){
    int n,k,d;
    cin >> n >> k >> d;
    for(int i = 1;i <= n;i ++)f[i][i] = 1;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            for(int k = 1;k <= n;k ++){
                if(j >= k){
                    f[i+j][j] += f[i][k];
                    f[i+j][j] %= mod;
                }
                else{
                    f[i+j][k] += f[i][k];
                    f[i+j][k] %= mod;
                }
            }
        }
    }
    int sum = 0;
    for(int i = d;i <= k;i ++){
        sum += f[n][i];
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}