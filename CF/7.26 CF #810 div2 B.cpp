#include<iostream>
using namespace std;
const int N = 100010;
void solve(){
    int n,m;
    cin>>n>>m;
    int a[N];
    int cnt[N] = {0};
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        cnt[i] = 0;
    }
    int x[N],y[N];
    for(int i = 1;i <= m;i ++){
        cin>>x[i]>>y[i];
        cnt[x[i]]++;
        cnt[y[i]]++;
    }
    int ans = 999999999;
    if(m % 2 == 0)ans = 0;
    for(int i = 1;i <= n;i ++){
        if(cnt[i] % 2 == 1){
            ans = min(ans,a[i]);
        }
    }
    for(int i = 1;i <= m;i ++){
        if(cnt[x[i]] % 2 == 0 && cnt[y[i]] % 2 == 0){
            ans = min(ans,a[x[i]]+a[y[i]]);
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}