#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

const int N = 1e6+50;
int a[N];

int main(){
    string s;
    cin >> s;
    memset(a,0,sizeof a);
    int n = s.length();
    stack<int> st;
    for(int i = 0;i < n;i ++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(!st.empty()){
                a[i] = 1;
                a[st.top()] = 1;
                st.pop();
            }
        }
    }
    int maxm = 0,cnt = 1,al = 0;
    for(int i = 0;i < n;i ++){
        if(a[i]){
            al ++;
        }
        else{
            al = 0;
        }
        if(al == maxm && maxm != 0)cnt ++;
        else if(al > maxm){
            maxm = al;
            cnt = 1;
        }
    }
    cout << maxm << ' ' << cnt << endl;
    return 0;
}