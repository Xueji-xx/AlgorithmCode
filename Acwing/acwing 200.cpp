#include<iostream>
using namespace std;

#define int long long
const int N = 50010;
typedef pair <int,int> PII;

PII fact[N];
int pri[N],cnt;
bool vis[N];
int divs[N],cntd;
int n;
int res;

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

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

void dfs(int u,int p){
    if(u == cnt){
        divs[cntd++] = p;
        return;
    }
    for(int i = 0;i <= fact[u].second;i ++){
        dfs(u+1,p);
        p *= fact[u].first;
    }
}

signed main(){
    get_prime(50000);
    cin>>n;
    while(n--){
        int a0,a1,b0,b1;
        cin>>a0>>a1>>b0>>b1;
        int d = b1;
        int cntf = 0;
        for(int i = 0;pri[i] <= d / pri[i];i ++){
            int p = pri[i];
            if(d % p == 0){
                int s = 0;
                while(d % p == 0)s ++,d /= p;
                fact[cntf++] = {p,s};
            }
        }
        if(d > 1)fact[cntf++] = {d,1};

        cntd = 0;
        dfs(0,1);

        int res = 0;
        for(int i = 0;i < cntd;i ++){
            int x = divs[i];
            if(gcd(x,a0) == a1 && x * b0 / gcd(x,b0) == b1)res++;
        }
        cout<<res<<endl;
    }
    return 0;
}