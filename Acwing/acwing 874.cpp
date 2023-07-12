#include<iostream>
using namespace std;
const int N = 1e6+50;
int pri[N],phi[N];
bool vis[N];
int cnt,n;


int f(int n){
    phi[1] = 1;
    for(int i = 2;i <= n;i ++){
        if(!vis[i]){
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(int j = 0;pri[j] <= n / i;j ++){
            vis[pri[j] * i] = true;
            if(i % pri[j] == 0){
                phi[i * pri[j]] = phi[i] * pri[j];
                break; 
            }
            phi[i * pri[j]] = phi[i] * (pri[j] - 1);
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i ++)ans += phi[i];
    return ans;
}   

int main(){
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}