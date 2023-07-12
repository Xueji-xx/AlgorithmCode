#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x,int y){
    return x > y;
}

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    int sum[200] = {0};
    int x = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        x += a[i];
        sum[i] = sum[i-1] + a[i];
    }
    if(x == n * a[1]){
        cout<<"NO"<<endl;
        return;
    }
    sort(a+1,a+1+n);
    int l = 1,r = n;
    cout<<"YES"<<endl;
    while(l <= r){
        if(l == r)cout<<a[l]<<' ';
        else cout<<a[l] <<' '<<a[r]<<' ';
        l++;
        r--;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}