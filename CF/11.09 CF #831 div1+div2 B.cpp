#include <iostream>
using namespace std;
#define int long long



signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int maxm = 0;
        int sum = 0;
        for(int i = 0;i < n;i ++){
            int x,y;
            cin>>x>>y;
            sum += min(x,y);
            maxm = max(maxm,max(x,y));
        }
        cout<<sum*2+maxm*2<<endl;
    }
    return 0;
}