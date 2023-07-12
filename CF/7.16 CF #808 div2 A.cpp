#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5] = {0};
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 1;i < n;i ++){
        if(a[i] % a[0] != 0){
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