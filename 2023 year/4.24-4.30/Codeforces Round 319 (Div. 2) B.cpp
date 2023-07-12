#include <iostream>
using namespace std;
const int M = 1e3+50;
bool f[2][M];

int main(){
    int n,m;
    cin >> n >> m;
    if(n > m){
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        x %= m;
        for(int j = 0;j < m;j ++){
            if(f[(i - 1) & 1][j]){
                f[i&1][j] = f[i & 1][(j+x) % m] = 1;
            }
            f[i & 1][x] = 1;
        }
    }
    cout << (f[n & 1][0] ? "YES" : "NO") << endl;
    return 0;
}