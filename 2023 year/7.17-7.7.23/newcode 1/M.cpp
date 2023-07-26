#include <iostream>
using namespace std;

ll _gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll ans=_gcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return ans;
}
ll extend_gcd(ll a,ll b,ll c)
{
    ll x,y;
    ll gcd=_gcd(a,b,x,y);
    if(c%gcd)
        return -1;
    x=x*c/gcd;
    x%=b;
    for(int i=1;i<=gcd;i++)//方程所有解
        ans[i]=(x+(i-1)*(b/gcd))%b;
}



int main(){
    int A,b,x,n,m;
    cin>>A>>b>>x;
    if(A < b)swap(A,b);
    int a=A%b;
    int k=A/b;
   //ma+nb=x, 解mn,n尽可能大
        m=1;
        n=0;

    if(k*m<=n)
    {
        cout<<2*m+2*(n-k*m)<<endl;
    }
    else
    {
        cout<<2*m+2*(k*m-n)-1<<endl;
    }




    return 0;
}