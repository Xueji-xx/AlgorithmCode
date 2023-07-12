#include<iostream>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n+50];
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum += a[i];
    }
    if(sum - m < 0)cout<<0<<endl;
    else cout<<sum - m<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}