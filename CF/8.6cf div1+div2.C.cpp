#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6+50;
#define int long long
int a[N],d[N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i ++){
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    for(int i = 2;i <= m;i ++){
        d[i] = a[i] - a[i-1] - 1;
    }
    d[1] = a[1] + n - a[m] - 1;
    sort(d + 1,d + m + 1);
    int ans = n;
    for(int i = m;i >= 1;i --){
        int th = d[i] - 4 * (m - i + 1) + 3;
        if(th == 0)ans -= 1;
        else if(th > 0)ans -= th;
    }
    cout<<ans<<endl;
}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}