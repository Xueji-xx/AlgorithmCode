#include <iostream>
using namespace std;

void solve(){
    int l,r;
    cin >> l >> r;
    int ans = 0;
    int t = l;
    for(int i = l;i <= l + 100 && i <= r;i ++){
        int x = i;
        int maxm = 0,minn = 100;
        while(x){
            int p = x % 10;
            x /= 10;
            maxm = max(maxm,p);
            minn = min(minn,p);
        }
        if(maxm - minn > ans){
            ans = maxm - minn;
            t = i;
        }
    }
    cout << t << endl;
}


int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}