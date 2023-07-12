#include <iostream>
#include <algorithm>
using namespace std;
#define int long long


signed main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    else if(n == 2){
        cout << 2 << endl;
        return 0;
    }
    else if(n == 3){
        cout << 6 << endl;
        return 0;
    }
    if(n % 2){
        cout << n * (n-1) * (n-2);
    }
    else{
        int a = n * (n - 1) * (n - 3);
        if(__gcd(n,n-3) != 1){
            a = n * (n - 1) * (n - 4);
        }
        int b = (n - 1) * (n - 2) * (n - 3);
        cout << max(a,b);
    }
    return 0;
}