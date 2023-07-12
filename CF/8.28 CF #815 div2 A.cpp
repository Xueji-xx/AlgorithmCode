#include<iostream>
using namespace std;
#define int long long

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x,y;
    x = a * d;
    y = b * c;
    if(x == y)cout<<0<<endl;
    else if(a == 0 || c == 0)cout<<1<<endl;
    else if(x % y == 0 || y % x == 0)cout<<1<<endl;
    else cout<<2<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}