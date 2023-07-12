#include<iostream>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 0;i < n;i ++)cin>>a[i];
    sort(a,a+n);
    cout<<a[n-1] + a[n-2] - a[0] -a[1]<<endl;
}



int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}