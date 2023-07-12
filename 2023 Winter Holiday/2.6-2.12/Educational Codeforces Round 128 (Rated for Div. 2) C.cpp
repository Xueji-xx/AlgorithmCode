#include <iostream>
using namespace std;

int a[200050];

void solve(){
    string s;
    cin>>s;
    int cnt = 0;
    s = '1' + s;
    for(int i = 1;i < s.length();i ++){
        a[i] = a[i-1] + (s[i] == '0');
        if(s[i] == '1')cnt++;
    }
    int res = cnt;
    for(int i = cnt;i < s.length();i ++){
        res = min(res,a[i] - a[i-cnt]);
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}