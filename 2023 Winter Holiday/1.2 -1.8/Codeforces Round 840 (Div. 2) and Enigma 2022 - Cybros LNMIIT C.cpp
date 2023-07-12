#include <iostream>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    int maxm = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        maxm = max(a[i],maxm);
    }
    if(n == 1){
        cout<<a[1]<<endl;
    }
    else if(n == 2)cout<<max(a[2] + a[1] , 2 * abs(a[2] - a[1]))<<endl;
    else if(n == 3){
        int sum = a[1] + a[2] + a[3];
        int ans = max(max(a[3],a[1]),max(abs(a[3] - a[2]), abs(a[2] - a[1])));
        cout<<max(sum,3*ans)<<endl;
    }
    else cout<<maxm*n<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}