#include<iostream>
using namespace std;
const int N = 100003;

int qmi(int a,int b,int k){
    int res = 1;
    while(b){
        if(b & 1)res = res * a % k;
        a = a * a % k;
        b >>= 1;
    }
    return res;
}

signed main(){
    int n,m;
    cin>>m>>n;
    cout<<qmi(m,n,N)%mod - m * qmi(m-1,n-1,N)%mod<<endl;
    return 0;
}