#include<iostream>
using namespace std;
const int N = 2e5+50;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int sum[N] = {0};
    for(int i = 1;i < n+1;i ++){
        sum[i] = sum[i-1] + (s[i-1] == 'W'?1:0);
    }
    int ans = 999999;
    for(int i = k;i < n+1;i ++){
        ans = min(ans,sum[i] - sum[i-k]);
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
