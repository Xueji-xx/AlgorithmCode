#include<iostream>
using namespace std;

inline int ex_gcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d =ex_gcd(b,a%b,x,y);
    int z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}


int main(){
    int a,b;
    cin>>a>>b;
    int x = 0,y = 0;
    ex_gcd(a,b,x,y);
    cout<<(x % b + b)% b;
    return 0;
}