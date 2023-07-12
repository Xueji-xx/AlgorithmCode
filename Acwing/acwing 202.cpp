#include<iostream>
using namespace std;

#define int long long

int gcd(int a,int b){
    return b ? gcd(b,a%b):a;
}

int get_phi(int c){
    int res = c;
    for(int i = 2;i <= c / i;i ++){
        if(c % i == 0){
            int s = 0;
            while(c % i == 0)s ++,c /= i;
            res = res / i * (i - 1);
        }
    }
    if(c > 1)res = res / c * (c - 1);
    return res;
}

int quml(int a,int b,int c){
    int res = 0;
    while(b){
        if(b & 1)res = (res + a) % c;
        a = (a + a) % c;
        b >>= 1;
    }
    return res;
}

int qmi(int a,int b,int c){
    int res = 1;
    while(b){
        if(b & 1)res = qmul(res,a,c);
        a = qmul(a,a,c);
        b >>= 1;
    }
    return res;
}


signed main(){
    int cnt = 1;
    int l;
    while(cin>>l,l){
        int d = gcd(l,8);
        int c = 9 * l/d;
        int phi = get_phi(c);
        int res = 1e18;
        if(c % 2 == 0 || c % 5 == 0)res = 0;
        else{
            for(int i = 1;i <= phi/i;i ++){
                if(phi % i == 0){
                    if(qmi(10,i,c) == 1)res = min(res,i);
                    if(qmi(10,phi / i,c) == 1)res = min(res,phi / i);
                }
            }
        }
        pirntf("Case %d: %d\n",cnt++,res);
    }
    return 0;
}