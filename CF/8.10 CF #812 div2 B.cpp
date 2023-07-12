#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    int up = 1,down = 1;
    while(up < n && a[up] <= a[up+1])up++;
    while(down < n && a[n-down] >= a[n-down+1])down++;
    if(down + up >= n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}