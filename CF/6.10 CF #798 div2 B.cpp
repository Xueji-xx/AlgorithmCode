#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+50];
    int b[n+50];
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        b[i] = i;
    }
    if(n == 1){
        cout<<-1<<endl;
        return;
    }
    for(int i = 1;i < n;i ++){
        if(a[i] == b[i])swap(b[i],b[i+1]);
    }
    if(a[n] == b[n])swap(b[n-1],b[n]);
    for(int i = 1;i <= n;i ++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
}