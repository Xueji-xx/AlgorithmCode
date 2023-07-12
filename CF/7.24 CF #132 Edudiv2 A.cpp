#include<iostream>
using namespace std;

void solve(){
    int k;
    cin>>k;
    int a[3];
    for(int i = 0;i < 3;i ++)cin>>a[i];
    int cnt = 1;
    if(a[k-1] == 0){
        cout<<"NO"<<endl;
        return;
    }
    else{
        k = a[k-1];
        if(a[k-1] == 0){
            cout<<"NO"<<endl;
            return;
        }
        else{
            k = a[k-1];
            cout<<"YES"<<endl;
            return;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}