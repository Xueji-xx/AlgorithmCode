#include<iostream>
using namespace std;
const int N = 2e5+50;

void solve(){
    int n;
    cin>>n;
    int a[N],b[N];
    for(int i = 0;i < n;i ++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i ++){
        cin>>b[i];
    }
    cout<<b[0] - a[0]<<' ';
    for(int i = 1;i < n;i ++){
        if(a[i] < b[i-1])cout<<b[i] - b[i-1]<<' ';
        else cout<<b[i] - a[i]<<' ';
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    //system("pause");
    return 0;
}