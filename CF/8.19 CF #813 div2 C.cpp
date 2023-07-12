#include<iostream>
#include<map>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    bool vis[n+5];
    map<int,int> g;
    for(int i = 0;i < n;i ++){
        cin>>a[i];  
        vis[a[i]] = false;
        g[a[i]] = max(g[a[i]],i);
    }
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    int cnt = -1; 
    for(int i = n-1;i >= 1;i --){
        if(a[i] < a[i-1]){
            cnt = i-1;break;
        }
    }
    if(cnt == -1){
        cout<<0<<endl;
        return;
    }
    int maxm = -1;
    for(int i = 0;i <= cnt;i ++){
        maxm = max(maxm,g[a[i]]);
    }
    int ans = 0;
    for(int i = 0;i <= maxm;i ++){
        if(a[i] && vis[a[i]] == false){
            vis[a[i]] = true;
            ans++;
        }
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