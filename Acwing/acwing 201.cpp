#include<iostream>
using namespace std;
#define int long long
const int N = 2000;
int pri[N],cnt;
bool vis[N];
int phi[N];

void get_phi(int n){
    phi[1] = 1;
    for(int i = 2;i <= n;i ++){
        if(!vis[i]){
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j = 0;pri[j] * i <= n;j ++){
            vis[pri[j] * i] = true;
            if(i % pri[j] == 0){
                phi[pri[j] * i] = pri[j] * phi[i];
                break;
            }
            else phi[pri[j] * i] = (pri[j] - 1) * phi[i];
        }
    }
}


signed main(){
    int t;
    cin>>t;
    get_phi(N);
    for(int j = 1;j <= t;j ++){
            int n;
            cin>>n;
            int res = 3;
            for(int i = 2;i <= n;i ++)res += phi[i]*2;
            cout<<j<<' '<<n<<' '<<res<<endl;
    }
    return 0;
}