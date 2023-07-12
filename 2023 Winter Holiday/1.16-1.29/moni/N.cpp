#include <iostream>
using namespace std;
#define int long long


signed main(){
    int n,m;
    cin>>n>>m;
    int s[n+10];
    for(int i = 1;i <= n;i ++){
        cin>>s[i];
    }
    for(int i = 1;i < n;i ++){
        s[i+1] = max(s[i+1],s[i] - m);
    }
    for(int i = n;i >= 2;i --){
        s[i-1] = max(s[i-1],s[i] - m);
    }
    for(int i = 1;i <= n;i ++){
        cout<<s[i]<<' ';
    }
    return 0;
}