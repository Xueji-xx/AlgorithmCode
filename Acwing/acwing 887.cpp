#include <iostream>
using namespace std;

int p;
int qmi(int a,int k,int p){
    int res = 1;
    while(k){
        if(k & 1)res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int C(int a,int b){
    if(b > a)return 0;
    int res = 1;
    for(int i = 1,j = a;i <= b;i ++,j --){
        res = res * j % p;
        res = res * qmi(i,p - 2,p) % p;
    }
    return res;
}

int lucas(int a,int b){
    if(a < p && b < p){
        return C(a,b);
    }
    return C(a % p,b % p) * lucas(a/p,b/p) % p;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b>>p;
        cout<<lucas(a,b)<<endl;
    }
    return 0;
}