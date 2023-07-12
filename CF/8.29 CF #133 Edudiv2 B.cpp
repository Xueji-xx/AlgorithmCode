#include<iostream>
#include<string.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 0;i < n;i ++){
        a[i] = i+1;
    }
    cout<<n<<endl;
    for(int i = 0;i < n;i ++){
        swap(a[i],a[0]);
        for(int j = 0;j < n;j ++){
            cout<<a[j]<<' ';
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