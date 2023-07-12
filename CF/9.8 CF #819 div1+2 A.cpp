#include<iostream>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    int mx = 0;
    for(int i = 1;i <= n-1;i ++){
        mx = max(mx,a[i] - a[i+1]);
    }
    mx = max(a[n] - a[1],mx);
    int x = a[1],b = a[n];
    sort(a+1,a+1+n);
    mx = max(a[n] - x,mx);
    mx = max(mx,b - a[1]);
    cout<<mx<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}