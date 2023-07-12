#include<iostream>
using namespace std;
const int N = 20;

int a[N],m[N];

void exgcd(int a,int b,int &x,int &y){
    if(!b){
        x = 1;
        y = 0;
    }
    else{
        exgcd(b,a%b,y,x);
        y -= a / b * x;
    }
}

int main(){
    int n;
    cin>>n;
    int M = 1;
    for(int i = 0;i < n;i ++){
        cin>>m[i]>>a[i];
        M *= m[i];
    }
    int res = 0;
    for(int i = 0;i < n;i ++){
        int M1 = M / m[i];
        int t,y;
        exgcd(M1,m[i],t,y);
        res += a[i] * M1 * t;
    }
    cout<<(res % M + M) % M<<endl;
    return 0;
}