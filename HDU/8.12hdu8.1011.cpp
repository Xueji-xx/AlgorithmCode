#include<iostream>
#include<math.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int ans = 0;
    for(int i = 1;i <= k;i ++){
        double x = k*1.0 / i;
        int j = ceil(x);
        if(i > n || j > m)continue;
        ans = max(ans,n / i + m / j - 2);
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}