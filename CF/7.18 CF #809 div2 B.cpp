#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    int ans[n+50] = {0},p[n+50] = {0};
    for(int i = 1;i <= n;i ++){
        if(!p[a[i]] || (i - p[a[i]])%2)ans[a[i]]++,p[a[i]] = i;
    }
    for(int i = 1;i <= n;i ++)cout<<ans[i]<<' ';
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}