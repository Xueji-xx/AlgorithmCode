#include<iostream>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    int a[n+50] = {0};
    a[0] = a[n+1] = 0;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    int ans = 0;
    int x = 0;
    int cnt = 0;
    for(int i = 1;i <= n+1;i ++){
        if(a[i] == 0){
            if(i - x > 1){
                cnt++;
            }
            x = i;
        }
    }
    if(cnt <= 1)cout<<cnt<<endl;
    else cout<<2<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}