#include<iostream>
using namespace std;

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    if(x != 0 && y != 0){
        cout<<-1<<endl;
        return;
    }
    else if(x == 0 && y == 0){
        cout<<-1<<endl;
        return;
    }
    else{
        int m = max(x,y);
        int cnt = 2;
        if((n - 1) % m == 0){
            while(cnt <= n){
                for(int i = 1;i <= m;i ++)cout<<cnt<<' ';
                cnt += m;
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}