#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

void solve(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    s = "1" + s;
    int n = s.length();
    priority_queue<int> h;
    vector<int> stk;
    int res = 0;
    for(int i = n;i;i --){
        if(s[i] == '('){
            res += stk.back() - i - 1;
            h.push(stk.back() - i - 1);
            stk.pop_back();
        }
        else{
            stk.push_back(i);
        }
    }
    while(h.size()){
        if(!k)break;
        k --;
        res -= h.top();
        h.pop();
    }
    cout << res / 2 << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}