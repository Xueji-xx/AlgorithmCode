#include <iostream>
using namespace std;
const int N = 1010;
int dp[N][N] = {0};

int main(){
    string s;
    string t;
    cin >> s >> t;
    for(int i = 0;i < s.length();i ++){
        for(int j = 0;j < t.length();j ++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[s.length()-1][t.length()-1] << endl;
    return 0;
}