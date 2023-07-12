#include <iostream>
#include <vector>
using namespace std;
#define int long long

const int N = 2e5+50;

int n,m,a[N],s[N];
vector<int> num;
int cnt[1000010];


void solve(){
    cin>>n;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        s[i] = s[i-1] ^ a[i];
    }
    long long ans = n * (n + 1) / 2;    
    cnt[0] = 1;
    for(int i = 1;i <= n;i ++){
        for(auto x:num){
            ans -= cnt[s[i] ^ x];
        }
        cnt[s[i]]++;
    }
    for(int i = 1;i <= n;i ++)cnt[s[i]]--;
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    num.push_back(0);
    for(int i = 1; ;i ++) {
         if(i * i > (1 << 19)) break;
         num.push_back({i * i});
    }
    while(t--)solve();
    return 0;
}