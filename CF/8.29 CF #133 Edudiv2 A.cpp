#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n == 1)cout<<2<<endl;
    else cout<<(n+2)/3<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}