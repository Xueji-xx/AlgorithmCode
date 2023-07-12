#include<iostream>
using namespace std;

void solve(){
    int a;int b;
    b = 0;
    cin>>a;
    if(a < 0){
        cout<<0<<endl;
        return;
    }
    else{
        getchar();
        cin>>b;
        cout<<a+b*20<<endl;
        return;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}