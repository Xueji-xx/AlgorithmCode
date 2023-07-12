#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n+50];
    ll sum = 0;
    for(ll i = 0;i < n;i ++){
        cin>>a[i];
        sum += a[i] / k;
        a[i] %= k;
    }
    sort(a,a+n);
    ll l = 0,r = n-1;
    while(l < r){
        if(a[l] + a[r] >= k)sum += (a[l]+a[r])/k,l++,r--;
        else l++;
    }
    cout<<sum<<endl;
}



int main(){
    ll t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
