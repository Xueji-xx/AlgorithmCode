#include<iostream>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int te=1;
        while(n%2==0){
            n/=2;
            te*=2;
        }
        if(n==1)//是2的n次方，没法分成奇数和偶数的乘积
            cout<<-1<<endl;
        else
            cout<<min(2*te,n)<<endl;
    }
}