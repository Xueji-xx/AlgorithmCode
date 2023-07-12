#include <iostream>
#include <math.h>
using namespace std;

const int N = 2e5+50;
int a[N];
int n,m;
int f[N][18];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i ++)cin >> a[i];
    for(int j = 0;j < 18;j ++){
        for(int i = 1;i + (1 << j) <= n;i ++){
            if(!j)f[i][j] = a[i];
            else f[i][j] = max(f[i][j-1],f[i+(1 << j-1)][j-1]);
        }
    }
    cin >> m;
    while(m --){
        int l,r;
        cin >> l >> r;
        int len = r - l + 1;
        int k = log2(len);
        cout << max(f[l][k],f[r - (1 << k) + 1][k]) << endl;
    }
    return 0;
}