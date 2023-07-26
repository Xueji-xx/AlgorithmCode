#include <iostream>
using namespace std;

const int mod = 1e9+7;
int n,P;
int qmi(int x,int y,int p = mod){
    int res = 1;
    while(y){
        if(y & 1)res = 1ll *  res * x % p;
        x = 1ll * x * x % p;
        y >>= 1;
    }
    return res;
}


int main(){
    int t;
    cin >> t;
    while(t --){
        scanf("%d %d",&n,&P);
        if(n == 0){
            printf("%d\n",0);
        }
        else if(n < 6 || !(n & 1)){
            printf("%d\n",(n / 2) * 15ll % mod + 15);
        }
        else{
            int t = n / 6;//购买商品的轮数
            int P1 = (1 - qmi(1 - P + mod,t) + mod) % mod;
            int P2 = (1 - (qmi(1 - P + mod,t) + 1ll *  qmi(1 - P + mod,t - 1) * P % mod * t % mod) % mod + mod) % mod;
            int PP = (1 - 1ll * (1 - P1 + mod) * (1 - P2 + mod) % mod + mod) % mod;
            int p1 = 1ll *PP * P1 % mod;
            int p2 = 1ll * PP * qmi(1 - P + mod,t) % mod * P2 % mod;
            int p3 = 1ll * PP * qmi(1 - P + mod,t) % mod * (1ll * qmi(1 - P + mod,t - 1) * P % mod * t % mod) % mod;
            int p4 = (1 - ((p1 + p2) % mod + p3) % mod + mod) % mod;
            cout << (((15ll * (n / 2) % mod + 22) * p1 % mod + (15ll * (n / 2) % mod + 21) * p2 % mod) % mod + ((15ll * (n / 2) % mod + 18) * p3 % mod + (15ll * (n / 2) % mod + 15) * p4 % mod) % mod) % mod << endl;
        }
    }
    return 0;
}