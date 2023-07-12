#include <string.h>
#include <iostream>
using namespace std;

const int N = 55, M = 50050;

int T, n;
int f[N][M];

int dp(int a, int b) {
    int &v = f[a][b];
    if (v != -1) return v;
    if (!a) return v = b & 1;
    if (b == 1) return dp(a + 1, 0);

    if (a && !dp(a - 1, b)) return v = 1;
    if (b && !dp(a, b - 1)) return v = 1;
    if (a >= 2 && !dp(a - 2, b + (b ? 3 : 2))) return v = 1; 
    if (a && b && !dp(a - 1, b + 1)) return v = 1; 

    return v = 0;
}
int main() {
    memset(f, -1, sizeof f);
    cin>>T;
    while (T -- ) {
        cin>>n;
        int a = 0, b = 0;
        for (int i = 0; i < n; ++ i) {
            int x;
            cin>>x;
            if (x == 1) ++ a;
            else b += b ? x + 1 : x;
        }
        if (dp(a, b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
