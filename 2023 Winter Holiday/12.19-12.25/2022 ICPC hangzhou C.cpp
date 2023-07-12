#include <iostream>
#include <string.h>
using namespace std;

const int N = 3500;
int f[N][N][2],w[15];

int main(){
    int n,k;
    cin >> n >> k;
    memset(f,-0x3f,sizeof f);
    f[0][0][0] = 0;
    for(int i = 1;i <= n;i ++){
        int p;
        cin>>p;
        for(int j = 1;j <= p;j ++)cin>>w[j];
        for(int j = k - 1;j >= 0;j --){
            f[i][j][0] = f[i-1][j][0];
            f[i][j][1] = f[i-1][j][1];
            if(j + p <= k){
                f[i][j+p][0] = max(f[i][j+p][0],f[i-1][j][0] + w[p]);
                f[i][j+p][1] = max(f[i][j+p][1],f[i-1][j][1] + w[p]);
            }
            for(int a = 1;a < p;a ++){
                if(j + a <= k){
                    f[i][j+a][1] = max(f[i][j+a][1],f[i-1][j][0] + w[a]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= k;j ++){
            ans = max(ans,f[i][j][0]);
            if(j == k)ans = max(f[i][j][1],ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}