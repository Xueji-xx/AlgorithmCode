#include<iostream>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    while(a && b){
        cout<<0;
        a--;
        cout<<1;
        b--;
    }
    for(int i = 0;i < a;i ++){
        cout<<0;
    }
    for(int i = 0;i < b;i ++){
        cout<<1;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}