#include<iostream>
using namespace std;
const int P = 131;
const int N = 1e5+50;
typedef unsigned long long ULL;
ULL h[N],p[N];

ULL get(int l,int r){
    return h[r] - h[l] * p[r - l + 1];
}


int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s = '1' + s;
    p[0] = 1;
    for(int i = 1;i <= n;i ++){
        h[i] = h[i-1] * P + s[i];
        p[i] = p[i-1] * P;
    }
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1) == get(l2,r2)){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}