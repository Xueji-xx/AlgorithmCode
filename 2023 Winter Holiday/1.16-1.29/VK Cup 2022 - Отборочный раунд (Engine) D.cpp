#include <iostream>
#include <map>
using namespace std;
#define int long long

map<int,int> f[60];
int a[60];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1;i <= n;i ++)f[i].clear();
        for(int i = 1;i <= n;i ++)cin>>a[i];
        int ans = 1;
        for(int i = 2;i <= n;i ++){
            for(int j = 1;j < i;j ++){
                int t = a[i] - a[j];
                for(int k = 1;k * k < t;k ++){
                    if(t % k || (k + t / k) % 2)continue;
                    int pre = (t / k - k) / 2;
                    int nxt = (t / k + k) / 2;
                    if(pre * pre < a[j] || nxt * nxt < a[i])continue;
                    if(f[j].count(pre))f[i][nxt] = max(f[i][nxt] , f[j][pre]+1);
                    else f[i][nxt] = max(f[i][nxt],(long long)2);
                    ans = max(ans,f[i][nxt]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}