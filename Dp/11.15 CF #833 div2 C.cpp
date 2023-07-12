#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;
#define int long long
const int N = 2e5+50;
int a[N],sum[N];
#define endl '\n'

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(a,0,sizeof a);
        memset(sum,0,sizeof sum);
        for(int i = 1;i <= n;i ++){
            cin>>a[i];
        }
        for(int i = 1;i <= n;i ++){
            sum[i] = sum[i-1] + a[i];
        }
        vector<int>pos;
        pos.clear();
        for(int i = 1;i <= n;i ++){
            if(a[i] == 0)pos.emplace_back(i);
        }
        int ans = 0;
        pos.emplace_back(n+1);
        int len = pos.size();
        for(int i = 1;i < pos[0];i ++){
            ans += (sum[i] == 0);
        }
        for(int i = 0;i < len-1;i ++){
            map<int,int> f;
            f.clear();
            for(int j = pos[i];j < pos[i+1];j ++){
                f[sum[j]]++;
            }
            int maxm = 0;
            for(auto &j : f)maxm = max(maxm,j.second);
            ans += maxm;
        }
        cout<<ans<<endl;
    }
    return 0;
}