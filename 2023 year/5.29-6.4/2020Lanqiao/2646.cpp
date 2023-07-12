#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

#define int long long



signed main(){
    int p,q;
    cin >> p >> q;
    int l;
    cin >> l;
    int d = l / pow(10,q - p + 1);
    l -= d;
    int y = pow(10,q) - pow(10,p-1);
    int gcd = __gcd(l,y);   
    l /= gcd;
    y /= gcd;
    cout << l << ' ' << y << endl;
    return 0;
}