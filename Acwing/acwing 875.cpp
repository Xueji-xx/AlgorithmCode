#include<iostream>
using namespace std;
#define ll long long

int quick_pow(int a,int b,int p){
    int res = 1 % p;
    while(b){
        if(b & 1){
            res = (ll)res * a % p;
        }
        k >>= 1;
        a = (ll)a * a % p;
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,p;
        cin>>a>>b>>p;
        cout<<quick_pow(a,b,p)<<endl;
    }
    return 0;
}