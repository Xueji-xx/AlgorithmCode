#include <iostream>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    int cnt1 = 0,cnt2 = 0;
    if(n & 1){
        int flag = 1;
        for(int i = 1;i <= m;i ++){
            if(i & 1){
                cout << 'x';
                cnt1 ++;
            }
            else {
                cout << 'o';
                cnt2 ++;
            }
        }
        cout << endl;
        n -= 1;
    }
    for(int i = 1;i <= n;i ++){
        bool flag = (i & 1);
        int cnt = 0;
        int Flag = 1;
        if(flag){
            for(int j = 1;j <= m;j ++){
                cnt ++;
                if(cnt == 4){
                    Flag ^= 1;
                    cnt = 0;
                }
                if(Flag){
                    cout << 'o';
                    cnt2 ++;
                }
                else{
                    cout << 'x';
                    cnt1 ++;
                } 
            }
        }
        else{
            for(int j = 1;j <= m;j ++){
                cnt ++;
                if(cnt == 4){
                    Flag ^= 1;
                    cnt = 0;
                }
                if(Flag){
                    cout << 'x';
                    cnt1 ++;
                }
                else {
                    cout << 'o';
                    cnt2 ++;
                }
            }
        }
        cout << endl;
    }
    // cout << "-----------------" << endl;
    //cout << cnt1 << ' ' << cnt2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}