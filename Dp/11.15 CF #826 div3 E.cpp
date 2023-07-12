#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+10] = {0};
    int f[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        f[i] = 0;
    }
    f[0] = 1;
    for(int i = 0;i <= n;i ++){
        if(i - a[i] - 1 >= 0 && f[i - a[i] - 1])f[i] = 1;
        if(!f[i])continue;
        if(i + a[i+1] + 1 <= n)f[i + a[i+1] + 1] = 1;
    }
    if(!f[n])cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}