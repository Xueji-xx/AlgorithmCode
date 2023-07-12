#include<iostream>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    if(n == m){
        for(int i = 1;i <= n;i ++){
            cout<<(i&1);
        }
        return;
    }
    else{
        if((m - n)%2 == 1){
            cout<<-1;
        }
        else{
            for(int i = 1;i <= n;i ++){
                cout<<(i&1);
            }
            for(int i = n+1;i <= m;i ++){
                cout<<0;
            }
        }
        return;
    }
}

int main(){
    solve();
    return 0;
}