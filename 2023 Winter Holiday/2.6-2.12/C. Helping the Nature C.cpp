#include <iostream>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+10] = {0};
    int b[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        b[i] = a[i] - a[i-1];
    }
    int sum = 0;
    for(int i = n;i >= 2;i --){
        if(b[i] > 0)sum += b[i];
        else if(b[i] < 0){
            sum -= b[i];
            b[1] += b[i];
        }
    }
    cout<<sum + abs(b[1])<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}