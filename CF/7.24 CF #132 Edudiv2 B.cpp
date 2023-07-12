#include<iostream>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    long long a[n+5] = {0};
    long long sum1[n+5] = {0};
    long long sum2[n+5] = {0};
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++){
        sum1[i] = max(0ll,a[i-1] - a[i]) + sum1[i-1];
    }
    for(int i = n;i >= 1;i --){
        sum2[i] = sum2[i+1] + max(0ll,a[i+1] - a[i]);
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        if(x < y)cout<<sum1[y] - sum1[x]<<endl;
        else cout<<sum2[y] - sum2[x]<<endl;
    }
    system("pause");
    return 0;
}