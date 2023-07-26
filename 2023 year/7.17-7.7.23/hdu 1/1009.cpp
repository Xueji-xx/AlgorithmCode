#include <iostream>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --){
        int n,m,d;
        cin >> n >> m >> d;
        if(n * (d - 1) < m){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}