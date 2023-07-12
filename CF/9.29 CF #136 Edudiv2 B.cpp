#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int d[n+5];
    int a[n+5];
    for(int i = 1;i <= n;i ++)cin>>d[i];
    a[1] = d[1];
    for(int i = 2;i <= n;i ++){
        if(d[i] == 0){
            a[i] = a[i-1];
        }
        else{
            if(a[i-1] - d[i] > 0){
                cout<<-1<<endl;
                return;
            }
            else{
                a[i] = a[i-1] + d[i];
            }
        }
        
    }
    for(int i = 1;i <= n;i ++)cout<<a[i]<<' ';
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}