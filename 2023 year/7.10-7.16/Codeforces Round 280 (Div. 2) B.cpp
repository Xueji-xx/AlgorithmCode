//1200
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

signed main(){
    int n,l;
    cin >> n >> l;
    int a[n+10] = {0};
    for(int i = 1;i <= n;i ++)cin >> a[i];
    sort(a+1,a+n+1);
    int maxm = 0;
    for(int i = 2;i <= n;i ++){
        maxm = max(maxm,a[i] - a[i-1]);
    }
    double x = a[1] * 1.0;
    double y = (l - a[n])*1.0;
    printf("%.9lf",(double)max((double)maxm/2.0,max(x,y)*1.0));
    return 0;
}