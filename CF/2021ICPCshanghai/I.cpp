#include<iostream>
#include<climits>
using namespace std;
#define int long long
const int N = 105;
int val[N],t[N];
int f[2][N][6000];//��ǰ i ����Ʒ����ѡ�񷭱� j �����õ������ֵ��k Ϊ�����ѵĲ�ֵ
    
signed main(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i ++){
        cin>>val[i]>>t[i];
    }
    for(int i = 0;i <= k;i ++){
        for(int j = 0;j <= 5200;j ++){
            if(j == 2600)continue;
            f[0][i][j] = -LONG_LONG_MAX;
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= k;j ++){
            for(int k = 0;k <= 5200;k ++){
                int x = 0;
                if(i & 1)x = 1;
                else x = 0;
                f[x][j][k] = f[x^1][j][k];
                if(k - t[i] >= 0){//�����һ����������
                    f[x][j][k] = max(f[x][j][k],f[x^1][j][k - t[i]]+val[i]);
                }
                if(k + t[i] <= 5200){//����ڶ�����������
                    f[x][j][k] = max(f[x][j][k],f[x^1][j][k + t[i]]+val[i]);
                }
                if(j){
                    if(k - 2 * t[i] >= 0){
                        f[x][j][k] = max(f[x][j][k],f[x^1][j-1][k - 2*t[i]]+val[i]);
                    }
                    if(k + 2 * t[i] <= 5200){
                        f[x][j][k] = max(f[x][j][k],f[x^1][j-1][k + 2*t[i]]+val[i]);
                    }
                }
            }
        }
    }
    cout<<f[n & 1][k][2600]<<endl;
    return 0;
}