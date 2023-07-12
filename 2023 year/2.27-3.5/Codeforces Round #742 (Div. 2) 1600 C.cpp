#include <iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int x = 0;
    int y = 0;
    for(int i = 0;i < s.length();i ++){
        if(i & 1){
            x = x * 10 + (s[i] - '0');
        }
        else y = y * 10 + (s[i] - '0');
    }
    cout<<(x+1) * (y+1) - 2<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}