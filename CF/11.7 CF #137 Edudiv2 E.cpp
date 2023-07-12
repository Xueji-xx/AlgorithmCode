#include <iostream>
#include <string.h>
using namespace std;
#define int long long
const int N = 5010;
int f[N];

signed main(){
    int a,ta,b,tb;
    cin>>a>>ta>>b>>tb;
    int h,s;
    cin>>h>>s;
    memset(f,0x3f,sizeof f);
    f[0] = 0;
    for(int i = 1;i <= h;i ++){
        f[i] = min(f[max(0ll,i - (a - s))] + ta,f[max(0ll,i - (b - s))] + tb);
        for(int j = 1;j <= i;j ++){
            if(ta * j >= tb){
                int tmp = (j - 1) * (a - s) + (ta * j - tb)/tb * (b - s) + (a + b - s);
                f[i] = min(f[i],f[max(0ll,i-tmp)] + ta * j);
            }
            if(tb * j >= ta){
                int tmp = (j - 1) * (b - s) + (tb * j - ta)/ta * (a - s) + (a + b - s);
                f[i] = min(f[i],f[max(0ll,i-tmp)] + tb * j);
            }
        }
    }
    cout<<f[h]<<endl;
    return 0;
}