#include<iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int l = 0,r = s.length()-1;
    while(l < r && s[l] == s[r]){
        l++,r--;
    }
    while(l < r && s[l] == s[l+1])l += 2;
    if(l <= r)cout<<"Alice"<<endl;
    else cout<<"Draw"<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}