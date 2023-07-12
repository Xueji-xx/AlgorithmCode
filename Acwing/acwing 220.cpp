#include<iostream>
using namespace std;
const int N = 1e7+50;
#define int long long
int pri[N],phi[N],cnt;
bool vis[N];
int sum[N];
int ans;



void get_phi(int n){
    vis[1] = true;
    phi[1] = 1;
    for(int i = 2;i <= n;i ++){
        if(!vis[i]){
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j = 0;pri[j] * i <= n;j ++){
            vis[pri[j] * i] = true;
            if(i % pri[j] == 0){
                phi[pri[j] * i] = phi[i] * pri[j];
                break;
            }
            else phi[pri[j] * i] = (pri[j] - 1) * phi[i];
        }
    }
}


signed main(){
    int n;
    cin>>n;
    get_phi(n);
    for(int i = 2;i <= n;i ++){
        sum[i] = sum[i-1] + phi[i];
    }
    for(int i = 0;i < cnt;i ++){
        int poi = n / pri[i];
        ans += sum[poi] * 2 + 1;
    }
    cout<<ans<<endl;
    return 0;
}