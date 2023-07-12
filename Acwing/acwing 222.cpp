#include<iostream>
#include<cmath>
#define int long long
using namespace std;

inline int exgcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 0;
        y = 1;
        return a;
    }
    int d = exgcd(b,a%b,x,y);
    y -= (a / d) * x;
    return d;
}

signed main(){
    int x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    int a = m - n,b = l,c = y - x;
    int x1,y1;
    int d = exgcd(a,b,x1,y1);
    if(c % d == 0){
        int mod = abs(b/d);
        x1 = x1 * (c / d);
        int ans = (x1 % mod + mod) % mod;
        cout<<ans<<endl;
    }
    else cout<<"impossible"<<endl;
    return 0;
}