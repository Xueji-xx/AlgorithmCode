#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n+5];
    int maxm = 0;
    for(int i = 0;i < n;i ++){
        int x;
        cin>>x;
        a[x]++;
        maxm = max(maxm,x);
    }
    int ans = 0;
    for(int i = 1;i <= maxm;i ++){
        int cnt = 0;
        for(int j = 2;j <= maxm;j += i){
            cnt += a[j];
        }
        if(cnt >= 2)ans = max(ans,i);
    }
    cout<<ans<<endl;
    return 0;
}