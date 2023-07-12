#include<iostream>
using namespace std;
#define int long long
int n,m;

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

int C(int a,int b){
    return a * (a - 1) * (a - 2) / 6;
}

signed main(){
    cin>>n>>m;
    n ++,m ++;
    int res = C(n * m,3) - n * C(m,3) - m * C(n,3);
    n --,m --;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            res -= 2 * (n - i + 1) * (m - j + 1) * (gcd(i,j) - 1);
        }
    }
    cout<<res<<endl;
    return 0;
}