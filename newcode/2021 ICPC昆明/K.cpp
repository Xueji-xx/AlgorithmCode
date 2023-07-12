#include <iostream>
#include <cmath>
using namespace std;
#define int long long



signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int t = a * (n - 1) / b;
        if(t * b < a * (n - 1))cout<<t+1<<endl;
        else cout<<t<<endl;
    }
    return 0;
}