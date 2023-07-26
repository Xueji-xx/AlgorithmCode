#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string ans[200];
string anss[200];

void solve(){
    memset(ans,0,sizeof ans);
    memset(anss,0,sizeof anss);
    int n,z;
    cin >> n >> z;
    bool flag = true;
    if(n * z / 100 * 100 != n * z){
        flag = false;
    }
    int x = n * z / 100;
    int g = __gcd(z,100);
    int fenmu = 100/g;
    int fenzi = z / g;
    //cout << fenzi << ' ' << fenmu << endl;
    for(int i = 1;i <= n;i ++){
        string s;
        cin >> s;
        int cnt = 1;
        for(int j = (fenmu == 1 ? 0 : 1);j < s.length();j ++){
            if(cnt == fenmu){
                cnt = 1;
                ans[i] += string(fenzi,s[j]);
                continue;
            }
            if(s[j] == s[j-1]){
                cnt ++;
                if(cnt == fenmu){
                    cnt = 1;
                    ans[i] += string(fenzi,s[j]);
                    j ++;
                }
            }
            else{
                if(cnt != fenmu){
                    flag = false;
                }
            }
        }
    }
    for(int i = 0;i < n * fenzi / fenmu;i ++){//列
        int cnt = 1;
        int st = 0;
        for(int j = (fenmu == 1 ? 1 : 2);j <= n;j ++){//行
            //cout << j << endl;
            string s = ans[j];
            string t = ans[j-1];
            if(cnt == fenmu){
                cnt = 1;
                for(int k = 1;k <= fenzi;k ++){
                    anss[st + k] += s[i];
                }
                st += fenzi;
                continue;
            }
            if(s[i] == t[i]){
                //cout << '*' << endl;
                cnt ++;
                if(cnt == fenmu){
                    cnt = 1;
                    for(int k = 1;k <= fenzi;k ++){
                        anss[st + k] += s[i];
                    }
                    st += fenzi;
                    j ++;
                }
            }
            else{
                //cout << cnt << endl;
                if(cnt != fenmu){
                    //cout << '*' << endl;
                    cout << "error" << endl;
                    return;
                }
            }
        }
    }
    if(flag){
        //cout << '*' << endl;
        for(int i = 1;i <= n * z / 100;i ++){
            cout << anss[i] << endl;
        }
    }
    else{
        cout << "error" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}