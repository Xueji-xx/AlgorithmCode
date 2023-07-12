#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



void solve(){  
    int n;
    cin >> n;
    int a,b,c;
    a = b = c = 99999999;
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        string s;
        cin >> s;
        if(s[0] == '0' && s[1] == '1'){
            a = min(a,x);
        }
        else if(s[0] == '1' && s[1] == '0'){
            b = min(b,x);
        }
        else if(s[0] == '1' && s[1] == '1'){
            c = min(c,x);
        }
    }
    if(c == 99999999 && (a == 99999999 || b == 99999999)){
        cout << -1 << endl;
    }
    else cout << min(c,a+b) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}