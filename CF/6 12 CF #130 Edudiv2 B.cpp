#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int main(){
    int n,q;
    cin>>n>>q;
    ll a[n+50];
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll sum[n+50] = {0};
    for(int i = 1;i <= n;i ++){
        sum[i] = sum[i-1] + a[i];
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<sum[n-x+y]-sum[n-x]<<endl;
    }
    system("pause");
    return 0;
}