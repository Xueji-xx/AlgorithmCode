#include <iostream>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n+10] = {0};
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
            a[i] += a[i-1];
        }
        int ans = 0,l = 0,r = 1;
        int cnt = 0;
        while(r <= n){
            if(a[r] > a[l])l = r;
            if(cnt < a[l] - a[r]){
                cnt = a[l] - a[r];
                ans = l;
            }
            r ++;
        }
        cout << a[ans] << endl;
    } 
    return 0;
}