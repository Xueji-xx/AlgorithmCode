#include <iostream>
using namespace std;




int main(){
    int a[10];
    for(int i = 1;i <= 6;i ++)cin >> a[i];
    int ans = 0;
    int n = a[1] + a[2] + a[3];
    ans += n * n;
    ans -= a[1] * a[1] + a[3] * a[3] + a[5] * a[5];
    cout << ans << endl;
    return 0;
}