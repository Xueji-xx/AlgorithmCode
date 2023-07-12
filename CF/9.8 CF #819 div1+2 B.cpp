#include<iostream>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    if(m < n){
        cout<<"NO"<<endl;
    }
    else{
        if(n & 1){
            cout<<"YES"<<endl;
            cout<<m - n + 1<<' ';
            for(int i = 2;i <= n;i ++)cout<<1<<' ';
            cout<<endl;
        }
        else{
            if(m & 1)cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                for(int i = 0;i < 2;i ++){
                    cout<<(m-n)/2+1<<' ';
                }
                for(int i = 3;i <= n;i ++){
                    cout<<1<<" ";
                }
                cout<<endl;
            }
        }
    }

}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}