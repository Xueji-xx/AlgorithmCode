#include<iostream>
#include<map>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i = 1;i <= k;i ++)mp[i]++;
    int ans = 0;
    int a[n+5] = {0};
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        if(i <= k && !mp[a[i]])ans++;
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