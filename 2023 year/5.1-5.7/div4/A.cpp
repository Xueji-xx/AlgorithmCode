#include <iostream>
using namespace std;

string t = "codeforces";

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0;i < s.length();i ++){
            if(s[i] != t[i])ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}