#include<iostream>
using namespace std;

int n;
int a,b,c;
int w[20][20];
int f[50][20][20];

int main(){
    cin>>n;
    while(cin>>a>>b>>c,a || b || c)w[a][b] += c;
    for(int k = 2;k <= 2*n;k ++){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                int &t = f[k][i][j];
                if(k - i <= 0 ||k - i > n ||k - j <= 0 || k - j > n)continue;
                int v = w[i][k-i];
                if(i != j)v += w[j][k-j];
                t = max(t,f[k-1][i][j]);
                t = max(t,f[k-1][i-1][j]);
                t = max(t,f[k-1][i-1][j-1]);
                t = max(t,f[k-1][i][j-1]);
                t += v;
            }
        }
    }
    cout<<f[2*n][n][n]<<endl;
    return 0;
}