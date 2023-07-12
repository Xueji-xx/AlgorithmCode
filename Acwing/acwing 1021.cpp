#include<iostream>
using namespace std;

const int N = 3050;
int f[20][N];

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+10];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 0;i <= n;i ++)f[i][0] = 1;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            f[i][j] += f[i-1][j];
            if(j >= a[i])f[i][j] += f[i][j-a[i]];
        }
    }
    cout<<f[n][m];
    return 0;
}