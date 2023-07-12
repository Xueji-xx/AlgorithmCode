#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= i;j ++){
            if(j != 1 && j != i)cout<<0<<' ';
            else cout<<1<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}