#include <iostream>
using namespace std;

const int N = 310;
const int B = N *N;
const int mod = 998244353;

int f[N][B*2];

int main(){
    int n;
    cin>>n;
    int a[n+10];
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    f[2][a[2] + B] = 1;
    for(int i = 2;i < n;i ++){
        for(int j = -B + 300;j <= B-300;j ++){
            if(j){
                f[i+1][a[i+1] - j + B] = (f[i+1][a[i+1] - j + B] + f[i][j+B]) % mod;
                f[i+1][a[i+1] + j + B] = (f[i+1][a[i+1] + j + B] + f[i][j+B]) % mod;
            }
            else{
                f[i+1][a[i+1] + B] = (f[i+1][a[i+1] + B] + f[i][j+B]) % mod;
            }
        }
    }
    int ans = 0;
    for(int i = -B;i <= B ;i ++){
        ans = (ans + f[n][i + B]) % mod;
    }
    cout<<ans<<endl;
    return 0;
}