#include <iostream>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    n = n * 2 - 1;
    cout<<n<<endl;
    for(int i = 1;i <= n;i ++){
        cout<<i<<' '<<i<<endl;
    }
    return;
}

int main(){
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}