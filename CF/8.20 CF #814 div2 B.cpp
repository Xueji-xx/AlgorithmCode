#include<iostream>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    if(k & 1){
        cout<<"YES"<<endl;
        for(int i = 1;i <= n;i += 2){
            cout<<i<<' '<<i+1<<endl;
        }
    }
    else{
        if(k % 4 == 0)cout<<"NO"<<endl;
        else if(k % 4 == 2){
            cout<<"YES"<<endl;
            bool flag = false;
            for(int i = 1;i <= n;i += 2){
                if(!flag)cout<<i+1<<' '<<i<<endl;
                else cout<<i<<' '<<i+1<<endl;
                flag = !flag;
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