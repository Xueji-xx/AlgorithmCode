#include<iostream>
using namespace std;

const int N = 1010;
int f[10][N];
int a[] = {0,10,20,50,100};

int main(){
    int n;
    cin>>n;
    f[0][0] = 1;
    for(int i = 1;i <= 4;i ++){
        for(int j = 0;j <= m;j ++){
            for(int k = 0;a[i] * k <= j;j ++){
                f[i][j] += f[i-1][j-a[i]*k];
            }
        }
    }
    cout<<f[4][m];
    return 0;
}