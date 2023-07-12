#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
int cnt[30];
void solve(){
    string s;
    int n;
    cin >> n >> s;
    memset(cnt,0,sizeof cnt);
    if(n & 1){
        cout << -1 << endl;
        return;
    }
    for(int i = 0;i < n;i ++)cnt[s[i] - 'a']++;
    for(int i = 0;i < 26;i ++){ 
        if(cnt[i] > n / 2){
            cout << -1 << endl; 
            return;
        }
    }
        
    memset(cnt,0,sizeof cnt);
    int res = 0;
    for(int i = 0;i < n/2;i ++){
        if(s[i] == s[n-i-1]){
            cnt[s[i] - 'a'] ++;
            res ++;
        }
    }
    for(int i = 0;i < 26;i ++){
        if(cnt[i] > res / 2){
            cout << cnt[i] << endl;
            return;
        }
    }
    cout << (res + 1) / 2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}