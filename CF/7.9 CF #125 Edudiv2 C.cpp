#include<iostream>  
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    s = 'a'+s;
    int res = 0,cnt = 1;
    while(cnt <= n){
        if(s[cnt] == '('){
            if(cnt < n)res++,cnt += 2;
            else break;
        }
        else{
            int i = cnt + 1;
            while(i < n && s[i] == '(')i++;
            if(i <= n && s[i] == ')')res++,cnt = i+1;
            else break;
        }
    }
    cout<<res<<' '<<n-cnt+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}