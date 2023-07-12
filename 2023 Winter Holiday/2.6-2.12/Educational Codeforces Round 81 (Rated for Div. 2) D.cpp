#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int phi(int x){
    int ans = x;
    for(int i = 2;i <= x / i;i ++){
        if(x % i == 0){
            ans = ans / i * (i - 1);
            while(!(x%i))x /= i;
        }
    }
    if(x > 1)ans = ans / x * (x - 1);
    return ans;
}

void solve(){
    int a,m;
    cin>>a>>m;
    int x= __gcd(a,m);
    cout<<phi(m/x)<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}