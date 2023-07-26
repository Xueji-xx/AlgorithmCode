#include <iostream>
#include <math.h>
using namespace std;

#define int long long


signed main(){
    string a,b;
    cin >> a >> b;
    int A = 0,B = 0;
    for(int i = 0;i < a.length();i ++){
        A += 1ll * pow(2,i) * (a[a.length() - i - 1] - '0');
    }
    for(int i = 0;i < b.length();i ++){
        B += 1ll * pow(2,i) * (b[b.length() - i - 1] - '0');
    }
    if(A == 0 && B != 0){
        cout << -1 << endl;
    }
    else cout << abs(A - B) << endl;
    return 0;
}