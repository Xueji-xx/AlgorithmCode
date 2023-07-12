#include<iostream>
using namespace std;

void solve(){
    int a,b;
    a = b = 0;
    for(int i = 0;i < 4;i ++){
        int x;
        cin>>x;
        if(x)a++;
        else b++;
    }
    if(a == 0)cout<<0<<endl;
    else if(a == 4)cout<<2<<endl;
    else cout<<1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t-- )solve();
    system("pause");
    return 0;
}