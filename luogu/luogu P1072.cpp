#include<iostream>
using namespace std;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int a0,a1,b0,b1;
        cin>>a0>>a1>>b0>>b1;
        /*gcd(x,a0) = a1;
        gcd(x,b0) * b1 = x * b0*/
        int ans = 0;
        int p = a0/a1,q = b1/b0;
        for(int x = 1; x <= b1 / x;x ++){
            if(b1 % x == 0){
                if(x % a1 == 0 && gcd(x/a1,p) == 1 && gcd(q,b1/x) == 1)ans++;
                int y = b1/x;
                if(x == y)continue;
                if(y % a1 == 0 && gcd(y/a1,p) == 1 && gcd(q,b1/y) == 1)ans++;
            }
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}