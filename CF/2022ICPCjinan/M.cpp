#include <iostream>
using namespace std;
#define int long long
#define endl '\n'

int n,res;
int add(int a,int b){
    int s = a + b;
    int a1 = 0;
    int b1 = 0;
    while(a || b){
        a1 += a % 10;
        a /= 10;
        b1 = b % 10;
        b /= 10;
        a1 = a1 + b1 >= 10 ? 1 : 0;
        res += a1;
    }
    return s;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        res = 0;
        cin>>n;
        int a,b;
        cin>>a;
        for(int i = 1;i < n;i ++){
            cin>>b;
            a = add(a,b);
        }
        cout<<res<<endl;
    }
    return 0;
}