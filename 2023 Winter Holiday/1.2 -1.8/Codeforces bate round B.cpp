//1600
#include <iostream>
#include <stack>
using namespace std;

bool judge(string s){
    int i = 1;
    if(s[0] != 'R')return false;
    if(s[1] >= 'A' && s[1] <= 'Z')return false;
    while(s[i] >= '0' && s[i] <= '9')i++;
    if(s[i] == 'C')return true;
    return false;
}

void solve(){
    string s;
    cin>>s;
    if(judge(s)){
        int sum = 0;
        int i = 1;
        while(s[i] >= '0' && s[i] <= '9'){
            sum *= 10;
            sum += (s[i] - '0');
            i++;
        }
        i ++;
        //cout<<sum<<endl;
        int x = 0;
        while(s[i] >= '0' && s[i] <= '9'){
            x *= 10;
            x += (s[i] - '0');
            i++;
        }
        //cout<<x<<endl;
        stack<int> s;
        while(x){
            int a = x % 26;
            if(a == 0)a += 26,x--;
            s.push('A' + a - 1);
            x /= 26;
        }
        while(s.size()){
            cout<<char(s.top());
            s.pop();
        }
        cout<<sum<<endl;
    } 
    else{
        int i = 0;
        stack<int> a;
        while(s[i] >= 'A' && s[i] <= 'Z'){
            a.push(s[i] - 'A' + 1);
            i++;
        }
        int sum = 0;
        int pos = 1;
        while(a.size()){
            int c = a.top();
            a.pop();
            sum += c * pos;
            pos *= 26;
        }
        int x = 0;
        while(s[i] >= '0' && s[i] <= '9'){
            x *= 10;
            x += (s[i] - '0');
            i++;
        }
        cout<<'R'<<x<<'C'<<sum<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}