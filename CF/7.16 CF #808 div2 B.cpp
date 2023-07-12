#include<iostream>
using namespace std;

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int a[n+10];
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        a[i] = r/i*i;
        if(a[i] < l){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 1;i <= n;i ++)cout<<a[i]<<' ';
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}