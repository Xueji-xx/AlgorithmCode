#include<iostream>
using namespace std;
const int N = 40;
int f[N][N][N][N];
int cnt[10];    


int main(){
    int n,m;
    cin>>n>>m;
    int a[n+5];
    int b[m+5];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= m;i ++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int maxm;
    int pos;
    f[0][0][0][0] = a[1];   
    for(int i1 = 0;i1 <= cnt[1];i1 ++){
        for(int i2 = 0;i2 <= cnt[2];i2 ++){
            for(int i3 = 0;i3 <= cnt[3];i3 ++){ 
                for(int i4 = 0;i4 <= cnt[4];i4 ++){
                    if(i1 == 0 && i2 == 0 && i3 == 0 && i4 == 0)continue;
                    maxm = 0;
                    pos = 1 + i1 + i2*2 + i3*3 + i4*4;
                    if(i1 != 0)maxm = max(maxm,f[i1-1][i2][i3][i4] + a[pos]);
                    if(i2 != 0)maxm = max(maxm,f[i1][i2-1][i3][i4] + a[pos]);
                    if(i3 != 0)maxm = max(maxm,f[i1][i2][i3-1][i4] + a[pos]);
                    if(i4 != 0)maxm = max(maxm,f[i1][i2][i3][i4-1] + a[pos]);
                    f[i1][i2][i3][i4] = max(maxm,f[i1][i2][i3][i4]);
                }
            }
        }
    }
    cout<<f[cnt[1]][cnt[2]][cnt[3]][cnt[4]]<<endl;
    system("pause");
    return 0;
}