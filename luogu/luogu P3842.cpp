#include<iostream>
#include<math.h>
using namespace std;
const int N = 2e5+90;
int f[N][3];
//0左 1右

int main(){
    int n;
    cin>>n;
    int l[n+5],r[n+5];
    for(int i = 1;i <= n;i ++){
        cin>>l[i]>>r[i];
    }
    f[1][1] = r[1] - 1;
    f[1][0] = r[1] - l[1] + r[1] - 1;//走完线段
    for(int i = 2;i <= n;i ++){
        f[i][0] = min(f[i-1][0] + abs(l[i-1] - r[i]) + r[i] - l[i] + 1,f[i-1][1] + abs(r[i-1] - r[i]) + r[i] - l[i] + 1);
        f[i][1] = min(f[i-1][0] + abs(l[i-1] - l[i]) + r[i] - l[i] + 1,f[i-1][1] + abs(r[i-1] - l[i]) + r[i] - l[i] + 1);
    }
    cout<<min(f[n][0] + n - l[n],f[n][1] + n - r[n]);
    system("pause");
    return 0;
}