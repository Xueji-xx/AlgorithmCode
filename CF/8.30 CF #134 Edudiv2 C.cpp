#include<iostream>
#include<string.h>
using namespace std;



void solve(){
    int n;
    cin>>n;
    int ans[n+10][2];
    int a[n+10];
    int b[n+10];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(ans,0,sizeof ans);
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++)cin>>b[i];
    int top = n;
    for(int i = n;i >= 1;i --){
        int t = lower_bound(b + 1,b + n + 1,a[i]) - b;
        if(t < i){
            ans[i][0] = b[t] - a[i];
            ans[i][1] = b[top] - a[i];
        }
        else if(t == i){
            ans[i][0] = b[t] - a[i];
            ans[i][1] = b[top] - a[i];
            top = i-1;
        }
    }
    for(int i = 1;i <= n;i ++)cout<<ans[i][0]<<' ';
    cout<<endl;
    for(int i = 1;i <= n;i ++)cout<<ans[i][1]<<' ';
    cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}