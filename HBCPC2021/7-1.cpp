#include<iostream>
using namespace std;


int main(){
    double n;
    double x,y;
    cin>>n>>x>>y;
    printf("%.4lf",n - (n/x)*y);
    return 0;
}