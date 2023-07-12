#include<iostream>
#include<string.h>
#include<climits>
using namespace std;
const int N = 1e6+50;
#define int long long
int pri[N],cnt;
bool vis[N];

void get_prime(int n){
    vis[1] = true;
    for(int i = 2;i <= n;i ++){
        if(!vis[i])pri[cnt++] = i;
        for(int j = 0;pri[j] * i <= n;j ++){
            if(!vis[pri[j] * i])vis[pri[j] * i] = true;
            if(i % pri[j] == 0)break;
        }
    }
}


signed main(){
    int l,r;
    while(cin>>l>>r){
        get_prime(50000);
        memset(vis,0,sizeof vis);
        for(int i = 0;i < cnt;i ++){
            int p = pri[i];
            for(int j = max(2*p,(l+p-1)/p*p);j <= r;j += p){
                vis[j-l] = true;
            }
        }
        int cnt = 0;
        for(int i = 0;i <= r - l;i ++){
            if(!vis[i] && i + l > 1){
                pri[cnt++] = i + l;
            }
        }
        if(cnt < 2)cout<< "There are no adjacent primes." <<endl;
        else{
            int minn = INT_MAX,maxm = 0;
            for(int i = 0;i + 1 < cnt;i ++){
                int d = pri[i+1] - pri[i];
                if(d < pri[minn+1] - pri[minn])minn = i;
                if(d > pri[maxm+1] - pri[maxm])maxm = i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",pri[minn],pri[minn+1],pri[maxm],pri[maxm+1]);
        }
    }
    return 0;
}