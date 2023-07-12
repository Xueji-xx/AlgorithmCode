#include<iostream>
using namespace std;
const int mod = 1e6+7;
int f[110][110];


int main(){
    int n,m;
    cin>>n>>m;
    int a[n+5];
    f[0][0] = 1;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= m;j ++){
            for(int k = 0;k <= min(j,a[i]);k ++){
                f[i][j] = (f[i][j] + f[i-1][j-k]) % mod;
            }
        }
    }
    cout<<f[n][m]<<endl;
    system("pause");
    return 0;
}