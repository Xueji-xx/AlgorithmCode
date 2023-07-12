#include <iostream>
using namespace std;

#define int long long

signed main(){
    int a,b;
    cin >> a >> b;
    int sum = b - 1000 * a;
    for(int x = 0;x <= a;x ++){
        if((sum + 1000 * x) % 1500 == 0){
            int z = (sum + 1000*x) / 1500;
            if(a - z - x < 0)continue;
            if(z < 0)continue;
            cout << x << ' ' << a - z - x << ' ' << z << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}