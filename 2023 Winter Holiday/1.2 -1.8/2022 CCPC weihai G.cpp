#include <iostream>
using namespace std;
#define int long long

const int N = 2e6+50;
int a[N],sum[N];

int gcd(int a,int b){
    return b ? gcd(b,a % b):a;
}

signed main(){
    int x,q;
    cin>>x>>q;
    int pos = 1;
    while(pos < x)pos <<= 1;
    for(int i = 1;i <= pos;i ++){
        if(gcd(i*x^x,x) == 1)a[i] = 1;
        sum[i] = sum[i-1] + a[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l --;
        int ans1 = sum[l % pos] + (l/pos) * sum[pos];
        int ans2 = sum[r % pos] + (r/pos) * sum[pos];
        cout<<ans2 - ans1 <<endl;
    }
    return 0;
}