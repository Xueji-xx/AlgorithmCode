#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    cout<<(int)floor(n/3) - 2 <<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}