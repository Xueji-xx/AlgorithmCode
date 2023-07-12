#include<iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int cnt,que;
    cnt = que = 0;
    for(char c:s){
        if(c == '(')cnt++;
        else if(c == ')')cnt--;
        else if(c == '?')que++;
        if(cnt + que == 1){
            cnt = 1;
            que = 0;
        }
    }
    if(abs(cnt) == que)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}