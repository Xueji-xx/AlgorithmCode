#include <iostream>
#include <string.h>
using namespace std;
#define int long long
const int N = 60;
int map[N][N];

void solve(){
    memset(map,0,sizeof map);
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(n * a != m * b){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    
    int last = 1;
    for(int i = 1;i <= n;i ++){
        int cnt = 0;
        while(cnt < a){
            map[i][last] = 1;
            cnt ++;
            last = (last % m) + 1;
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

signed main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}