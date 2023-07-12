#include <iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;
    string t;
    t = s;
    t.reserve();
    bool flag = true;
    int cnt[30] = {0};
    for(int i = 0;i < s.length();i ++){
        cnt[s[i] - 'a'] ++;
        if(s[i] != t[i])flag = false;
    }
    for(int i = 0;i < 30;i ++){
        if(cnt[i] == s.length()){
            cout << -1 << endl;
            return;
        }
    }
    if(!flag){
        cout << s.length() << endl;
    }
    else cout << s.length() - 1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}