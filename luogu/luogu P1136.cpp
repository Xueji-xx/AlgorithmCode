#include <iostream>
#include <string.h>
using namespace std;
const int N = 510,M = 110;
int n,m,f[N][M][M][3];
//f[i][j][k][0]为遍历了字符串的前i位，改变了j个j和k个z，并且当前的这一位为j所能达到的最大价值
//f[i][j][k][1]为遍历了字符串的前i位，改变了j个j和k个z，并且当前的这一位为z所能达到的最大价值

int main(){
    cin>>n>>m;
    string s;
    cin>>s;
    s = '*' + s;
    memset(f,128,sizeof f);
    f[0][0][0][1] = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= m;j ++){
            for(int k = 0;k <= m;k ++){
                if(s[i] == 'z'){
                    f[i][j][k][1] = max(f[i-1][j][k][0]+1,f[i-1][j][k][1]);
                    if(k)f[i][j][k][0] = max(f[i-1][j][k-1][0],f[i-1][j][k-1][1]);
                }
                else{
                    f[i][j][k][0] = max(f[i-1][j][k][0],f[i-1][j][k][1]);
                    if(j)f[i][j][k][1] = max(f[i-1][j-1][k][0]+1,f[i-1][j-1][k][1]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= m;i ++){
        ans = max(ans,max(f[n][i][i][1],f[n][i][i][0]));
    }
    cout<<ans<<endl;
    return 0;
}