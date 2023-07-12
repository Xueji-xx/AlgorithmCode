#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+10] = {0};
    for(int i = 1,len;i <= n;i ++){
        cin>>len;
        len = min(len,i);
        a[i - len + 1]++;
        a[i+1]--;
    }
    for(int i = 1;i <= n;i ++){
        a[i] += a[i-1];
        if(a[i])cout<<1<<' ';
        else cout<<0<<' ';
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 