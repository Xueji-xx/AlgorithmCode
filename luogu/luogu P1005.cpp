#include <iostream>
#include <string.h>
using namespace std;
#define bll __int128_t
const int MAXM = 81;

int n,m;
int num[MAXM];
bll ans,p[MAXM],f[MAXM][MAXM];

inline int read() 
{
    int X=0,w=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}

void print(bll x)
{
    if(!x) return;
    if(x) print(x/10);
    putchar(x%10+'0');
}

bll dp(int l,int r){
    if(f[l][r] != -1)return f[l][r];
    if(r - l >= 1)f[l][r] = max(num[l] * p[m - (r - l)] + dp(l+1,r),dp(l,r-1) + num[r] * p[m - (r - l)]);
    else f[l][r] = num[l] * p[m - (r - l)];
    return f[l][r];
}

int main(){
    n = read();
    m = read();
    p[0] = 1;
    for(int i = 1;i <= m;i ++)p[i] = p[i-1] * 2;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            num[j] = read();
        }
        memset(f,-1,sizeof f);
        ans += dp(1,m);
    }
    if(!ans)cout<<0<<endl;
    else print(ans);
    return 0;
}