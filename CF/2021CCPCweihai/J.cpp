#include <iostream>
using namespace std;
#define int long long
#define endl '\n'

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int y = 180 * b / gcd(a,b*180);
        cout<<y - 1 <<endl;
    }
    return 0;
}