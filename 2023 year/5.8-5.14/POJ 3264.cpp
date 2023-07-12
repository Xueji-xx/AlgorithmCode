#include <iostream>
#include <math.h>
using namespace std;

const int N = 5e4+50;
int f[N][50];
int d[N][50];
int a[N];

int main(){
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        f[i][0]=d[i][0]=a[i];
    }
    for(int j = 1;j <= 18;j ++){
        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
            f[i][j] = max(f[i][j-1],f[i + (1 << j-1)][j-1]);
            d[i][j] = min(d[i][j-1],d[i + (1 << j-1)][j-1]);
        }
    }
    while(q --){
        int l,r;
        cin >> l >> r;
        if(l > r)swap(l,r);
        int k = (int)(log((r - l + 1)*1.0) / log(2.0));  
        int x = max(f[l][k],f[r - (1 << k) + 1][k]);
        int y = min(d[l][k],d[r - (1 << k) + 1][k]);
        cout << x - y << endl;
    }
    return 0;
}