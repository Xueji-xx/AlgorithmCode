#include<iostream>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    int a[n+10];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    int ans[n+10] = {0};
    int now = 0;
    int i;
    for(i = n;i >= 1 && now < q;i --){
        ans[i] = 1;
        if(now < a[i]){
            now++;
        }
    }
    for(i;i >= 1;i --){
        if(q >= a[i])ans[i] = 1;
    }
    for(int i = 1;i <= n;i ++)cout<<ans[i];
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}