#include<iostream>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 1;i <= n;i ++)a[i] = i;
    if(n & 1){
        for(int i = 2;i <= n;i += 2){
            swap(a[i],a[i+1]);
        }
    }
    else{
        for(int i = 1;i <= n;i += 2){
            swap(a[i],a[i+1]);
        }
    }
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