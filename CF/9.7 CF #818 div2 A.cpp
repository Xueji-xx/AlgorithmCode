#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    long long ans = n;
    ans += 2*(n/2 + n/3);
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}