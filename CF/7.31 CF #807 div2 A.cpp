#include<iostream>
#include<algorithm>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int a[2*n+5];
    for(int i = 0;i < 2*n;i ++)cin>>a[i];
    sort(a,a+2*n);
    int x = a[n];
    for(int i = 0;i < n;i ++){
        if(a[i+n] - a[i] < k){
            cout<<"NO"<<endl;
            return;
        } 
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}