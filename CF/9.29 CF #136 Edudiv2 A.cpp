#include<iostream>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    if((n > 1 && m > 3) || (n > 3 && m > 1))cout<<1<<' '<<1<<endl;
    else{
        cout<<n/2+1<<' '<<m/2+1<<endl;
    }
}



int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}