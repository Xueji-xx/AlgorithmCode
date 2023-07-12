#include<iostream>
using namespace std;
const int N = 1050;
int t[N],w[N];
int f[N][N];

int main(){
    int m,n;
    cin>>m>>n;
    for(int i = 1;i <= n;i ++){
        cin>>t[i]>>w[i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= m;j ++){
            f[i][j] = f[i-1][j];
            if(j >= t[i])f[i][j] = max(f[i][j],f[i-1][j-t[i]]+w[i]);
        }
    }
    cout<<f[n][m];
    return 0;
}