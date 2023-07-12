#include <iostream>
#include <map>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5+50;

int pre[N],nex[N],a[N],sum[N],sum2[N];



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    map<int,int> mp[2];
    mp[0][0] = 0;
    for(int i = 1;i <= n;i ++){
        pre[i] = -1;
        nex[i] = n + 1;
    }
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum[i] = sum[i-1] ^ a[i];
        sum2[i] = sum2[i-1] + (a[i] > 0);
        int bit = i & 1; 
        if(mp[bit ^ 1].find(sum[i]) != mp[bit^1].end()){
            int x = mp[bit^1][sum[i]];
            pre[i] = x + 1;
            nex[x+1] = min(nex[x + 1],i);
        }
        mp[bit][sum[i]] = i;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(sum[r] ^ sum[l-1]){
            cout<<-1<<endl;
            continue;
        }
        if(sum2[r] == sum2[l - 1]){
            cout<<0<<endl;
            continue;
        }
        int len = r - l + 1;
        if(len & 1){
            cout<<1<<endl;
            continue;
        }
        if(a[l] == 0 || a[r] == 0){
            cout<<1<<endl;
            continue;
        }
        if(pre[r] >= l || nex[l] <= r){
            cout<<2<<endl;
            continue;
        }
        cout<<-1<<endl;
    }
    return 0;
}