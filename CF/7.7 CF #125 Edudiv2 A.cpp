#include<iostream>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    if(a == 0 && b == 0)cout<<0<<endl;
    else if(a == 0 || b == 0)cout<<1<<endl;
    else{
        int r = 0;
        while(r*r < a*a+b*b)r++;
        if(r*r == a*a+b*b)cout<<1<<endl;
        else cout<<2<<endl;
    }
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}