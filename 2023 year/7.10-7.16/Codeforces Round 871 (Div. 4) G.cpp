#include <iostream>
using namespace std;

#define LL long long
#define endl '\n'
const int N = 1e7+50;
long long f[N];

void init(){
    f[1] = 1;
    for(int i = 2,k = 2;k <= 1000000;i ++){
        for(LL j = 1;j <= i;j ++,k ++){
            long long x = 1ll * k * k;
            f[k] = x;
            if(i > 1){
                if(j <= i - 1)f[k] += f[(i - 2) * (i - 1) / 2 + j];
                if(j > 1){
                    f[k] += f[(i - 2) * (i - 1) / 2 + j - 1];
                    if(i > 2 && j - 1 <= i - 2){
                        f[k] -= f[(i - 3) * (i - 2) / 2 + j - 1];
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    init();
    while(t --){
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}