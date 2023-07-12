#include<iostream>
using namespace std;
#define ll long long

ll quick_pow(int a,int k,int p){
    ll res = 1;
    while(k){
        if(k & 1)res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int a,p;
        cin>>a>>p;
        if(a % p == 0)cout<<"impossible"<<endl;
        else cout<<quick_pow(a,p-2,p)<<endl;
    }
    return 0;
}