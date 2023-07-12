#include<iostream>
using namespace std;

const int mod = 1e9+7 , N = 1e3+10;

int f[N][N];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i <= n;i ++)f[i][0] = 1;
    
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= n;j ++){
            f[i][j] = f[i-1][j] % mod;
            if(j >= i)f[i][j] = (f[i-1][j] + f[i][j-i]) % mod;
        }
    }
    cout<<f[n][n]<<endl;
    system("pause");
    return 0;
}