#include<iostream>
using namespace std;
int f[1100][1100];



int main(){
    int n,m;
    
    cin>>n;
    string a;
    cin>>a;
    a = '1' + a;
    
    string b;
    cin>>m;
    cin>>b;
    b = '1' + b;
    for(int i = 0;i <= m;i ++)f[0][i] = i;
    for(int i = 0;i <= n;i ++)f[i][0] = i;
    
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            f[i][j] = min(f[i-1][j]+1,f[i][j-1]+1);
            if(a[i] == b[j]){
                f[i][j] = min(f[i][j],f[i-1][j-1]);
            }
            else f[i][j] = min(f[i][j],f[i-1][j-1] + 1);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}