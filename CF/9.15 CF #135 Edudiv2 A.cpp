#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    int pos = 0;
    int maxm = 0;
    for(int i = 0;i < n;i ++){
        cin>>a[i];
        if(a[i] > maxm){
            maxm = a[i];
            pos = i;
        }
    }
    cout<<pos + 1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}