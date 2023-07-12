#include<iostream>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    int a[n+10] = {0};
    int div[n+10];
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        div[i] = a[i] - a[i-1];
    }
    int l,r,x;
    for(int i = 0;i < m;i ++){
        cin>>l>>r>>x;
        div[l] += x;
        div[r] -= x;
    }
    for(int i = 1;i <= n;i ++){
        a[i] = a[i-1] + div[i];
        cout<<a[i]<<' ';
    }
    return 0;
}