#include<iostream>
using namespace std;

const int N = 1e6+50;
const int MOD = 1e9+7;
int pri[N],cnt;
bool vis[N];

void get_prime(int n){
    vis[1] = true;
    for(int i = 2;i <= n;i ++){
        if(!vis[i])pri[cnt++] = i;
        for(int j = 0;pri[j] * i <= n;j ++){
            vis[pri[j] * i] = true;
            if(pri[j] % i == 0)break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    get_prime(n);
    for(int i = 0;i < cnt;i ++){
        int p = pri[i];
        int s = 0;
        for(int j = n;j;j /= p)s += j / p;
        res = (2 * s + 1) * res % MOD;
    }
    cout<<res<<endl;
    return 0;
}