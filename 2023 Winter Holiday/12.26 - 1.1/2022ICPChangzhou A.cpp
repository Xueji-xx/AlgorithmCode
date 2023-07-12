#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b,a % b,y,x);
    y -= (a/b)*x;
    return d;
}

signed main(){
    int n,m;
    cin>>n>>m;
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        sum += x;
    }
    int a,b,x,y,k,t;
    a = n;
    b = n * (n + 1) / 2;
    int gcd1 = __gcd(a,b);
    int gcd2 = __gcd(gcd1,m);
    int ans = sum % gcd2;

    exgcd(gcd1,m,k,t);
    k *= ((ans - sum) / gcd2) % m;
    k %= m;

    exgcd(a,b,x,y);
    x *= k,y *= k;

    cout<<ans<<endl;
    cout<< (x % m + m) % m <<' '<< (y % m + m) % m<<endl;
    return 0;
}