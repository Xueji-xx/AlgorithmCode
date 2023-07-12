#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+50;
int pos[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        pos[x] = i;
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        ans = __gcd(ans,abs(i - pos[i]));
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}