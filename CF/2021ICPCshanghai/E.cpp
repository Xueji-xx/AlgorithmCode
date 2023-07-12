#include<iostream>
#include<algorithm>
using namespace std;



int main(){
    int n,k;
    cin>>n>>k;
    int a[n+10];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans = 1;
    int pre = a[1];
    for(int i = 2;i <= n;i ++){
        if(a[i] - pre >= k){
            pre = a[i];
            ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}