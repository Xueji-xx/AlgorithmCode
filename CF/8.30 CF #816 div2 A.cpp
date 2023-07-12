#include<iostream>
using namespace std;

void solve(){
    int n,m,a,b;
    cin>>n>>m;
    a = min(n,m);
    b = max(n,m);
    if(a == 1 && b == 1)cout<<0<<endl;
    else cout<<b + a* 2 - 2<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}