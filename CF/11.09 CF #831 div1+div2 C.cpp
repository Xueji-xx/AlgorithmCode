#include <iostream>
#include <algorithm>
using namespace std;




int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+10] = {0};
        for(int i = 1;i <= n;i ++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        int ans = 0;
        for(int i = 1;i < n;i ++)ans = max(ans,a[n] + a[i+1] - 2*a[i]);
        for(int i = 2;i <= n;i ++)ans = max(ans,a[i]*2 - a[1] - a[i-1]);
        cout<<ans<<endl;
    }
    return 0;
}