#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;
    int cnt = 0;
    if(a == b){
        cout<<0<<endl;
        return;
    }
    for(int i = 0;i < n;i ++){
        if(a[i] != b[i]){
            cnt++;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}