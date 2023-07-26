#include <iostream>
using namespace std;

#define endl "\n"
#define int long long

void solve(){
    int n;
    int k,kk;
    cin >> n >> k;
    kk = k;
    string s;
    cin >> s;
    s = s + '1';
    if(n == 1){
        if(k & 1){
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
        return;
    }


    bool flag = true;
    for(int i = 0;i < s.length();i ++){
        if(k == 0){
            break;
        }
        if(s[i] == '0' && !flag){
            s[i] = '1';
        }
        else if(s[i] == '0' && flag){
            s[i] = '1';
            flag = false;
        }
        else if(s[i] == '1' && !flag){
            k --;
            flag = true;
            s[i] = '1';
        }
        else s[i] = '1';
    }
    if(k == kk && k == 1){
        s[s.length() - 2] = '0';
    }
    for(int i = 0;i < s.length()-1;i ++){
        cout << s[i];
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}