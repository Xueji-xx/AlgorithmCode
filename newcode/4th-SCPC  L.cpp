#include<iostream>
using namespace std;


int main(){
    long long t;
    scanf("%lld",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        if(n % 4 == 0 || n & 1)printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}