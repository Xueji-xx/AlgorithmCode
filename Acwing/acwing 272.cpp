#include<iostream>
using namespace std;
const int N = 3050;

int a[N],b[N];
int f[N][N];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++)cin>>b[i];

    for(int i = 1;i <= n;i ++){
        int maxm = 1;
        for(int j = 1;j <= n;j ++){
            f[i][j] = f[i-1][j];
            if(b[j] == a[i])f[i][j] = max(f[i][j],maxm);
            if(b[j] < a[i])maxm = max(maxm,f[i-1][j] + 1);
        }
    }

    int res = 0;
    for(int i = 0;i <= n;i ++)res = max(res,f[n][i]);
    cout<<res<<endl;
    return 0;
}