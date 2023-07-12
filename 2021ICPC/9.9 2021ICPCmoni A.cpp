#include<iostream>
using namespace std;
#define int long long

signed main(){
    int n,m;
    cin>>n>>m;
    if(n == 1 && m == 1){
        cout<<0<<endl;
        return 0;
    }
    if(n == 1){
        cout<<m-1<<endl;
    }
    else if(m == 1){
        cout<<n-1<<endl;
    }
    else{
        cout<<n*(m-1)<<endl;
    }
    system("pause");
    return 0;
}