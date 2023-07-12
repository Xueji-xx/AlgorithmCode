#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
int n,k;
cin>>n>>k;
int a[n+1];
int vis[n+1];
int pos; 
int cnt=0;
memset(vis,0,sizeof(vis));
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==1) pos=i;
    if(a[i]==i) vis[a[i]]=1,cnt++;
} 
    // cout<<"pos "<<pos<<endl;
    // cout<<"cnt "<<cnt<<endl;
if(cnt==n) cout<<0<<endl;//全在 
else{//不全在 
    if(k==n) cout<<1<<endl;//一次就能重排完 
    else{//不能一次排完 
    int p=1;
    for(int i=pos+1;i<=n;i++){
        if(a[i]==p+1){
            p++;
        }
    }
    //   cout<<"p "<<p<<endl;
            int tp=(n-p)/k+((n-p)%k?1:0);
    //   cout<<"tp "<<tp<<endl;
            cout<<tp<<endl;  
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}