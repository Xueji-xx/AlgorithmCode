#include <bits/stdc++.h>
#define ll long long
using namespace std;
stack<ll> num;
stack<char> op;
string str;
void f() {
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    ll x;
    if (c == '+') {
        x = a + b;
    } else if (c == '-') {
        x = a - b;
    } else if (c == '*') {
        x = a * b;
    } else {
        x = a / b;
    }
    num.push(x);
}


int main(){
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    cin >> str;
    for (int i = 0; i < str.size(); i ++) {
        auto c = str[i];
        if (isdigit(c)){
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j])) {
                x = x * 10 + str[j++] - '0';
            }
            i = j - 1;
            num.push(x);
        } 
        else if (c == '('){
            op.push(c);
        } 
        else if (c == ')'){
            while (op.top() != '(') f();
            op.pop();
        } 
        else{
            while (op.size() && pr[op.top()] >= pr[c]) f();
            op.push(c);
        }
    }
    while (op.size()) f();
    cout<<num.top()<<endl;
    return 0;
}