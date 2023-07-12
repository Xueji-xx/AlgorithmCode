#include<iostream>
using namespace std;
const int N = 55;
int w[N][N];
int f[2*N][N][N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin>>w[i][j];
        }
    }
    for(int k = 2;k <= n+m;k ++){
        for(int i = 1;i < k && i <= n;i ++){
            for(int j = 1;j < k && j <= n;j ++){
                int v = w[i][k-i];
                if(i != j)v += w[j][k-j];
                int &t = f[k][i][j];
                t = max(t,f[k-1][i][j]);
                t = max(t,f[k-1][i-1][j]);
                t = max(t,f[k-1][i-1][j-1]);
                t = max(t,f[k-1][i][j-1]);
                t += v;
            }
        }
    }
    cout<<f[n+m][n][m];
    return 0;
}