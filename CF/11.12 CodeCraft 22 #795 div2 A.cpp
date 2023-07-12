#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    int odd = 0,even = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        if(a[i] & 1)odd++;
        else even++;
    }
    cout<<min(odd,even)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}