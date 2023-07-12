#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int maxm = 0;
    int ans = 0;
    int a[n+10] = {0};
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(a[i] == 0){
            maxm ++;
        }
        if(a[i] == 1){
            ans = max(ans,maxm);
            maxm = 0;
        }
    }
    cout << max(ans,maxm) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}