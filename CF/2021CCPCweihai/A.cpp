#include <iostream>
using namespace std;
#define int long long
#define endl '\n'

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int num[n+10] = {0};
    for(int i = 1;i <= n-1;i ++){
        int x,y;
        cin>>x>>y;
        num[x]++;
        num[y]++;
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        if(num[i] > 3){
            cout<<0<<endl;
            return 0;
        }
        else if(num[i] == 3)ans++;
    }
    cout<<n - ans<<endl;
    return 0;
}