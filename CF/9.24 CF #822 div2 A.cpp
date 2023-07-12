#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 0;i < n;i ++)cin>>a[i];
    sort(a,a+n);
    int minn = 99999999999;
    for(int i = 1;i < n-1;i ++){
        minn = min(abs(a[i] - a[i-1] + a[i+1] - a[i]),minn);
    }
    cout<<minn<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}