#include<iostream>
#include<math.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int num = sqrt(n);
    if(num*num != n)num++;
    for(int i = 1;i <= n;i += num){
        for(int j = min(n,i+num-1);j >= i;j --){
            cout<<j<<' ';
        }
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