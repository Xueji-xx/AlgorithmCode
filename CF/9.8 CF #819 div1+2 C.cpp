#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = n;
    for(int i = 1;i <= 2*n-1;i ++){
        if(s[i] == '(' && s[i-1] == ')')ans--;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}