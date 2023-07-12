#include <iostream>
using namespace std;



int main(){
    int n,m;
    cin >> n >> m;
    int ans = (n+1)/2 + (m+1)/2 - 1;
    if(n % 2 == 0 || m % 2 == 0)ans ++;
    cout << ans << endl;
    return 0;
}