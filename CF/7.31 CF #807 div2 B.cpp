#include<iostream>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 0;i < n;i ++)cin>>a[i];
    bool flag = true;
    int sum = 0;
    for(int i = 0;i < n-1;i ++){
        if(a[i] == 0 && flag)continue;
        else{
            flag = false;
            if(a[i] == 0)sum += 1;
            else sum += a[i];
        }
    }
    cout<<sum<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}