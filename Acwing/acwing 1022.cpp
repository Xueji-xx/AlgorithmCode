#include<iostream>
using namespace std;
const int N = 150;
int num[N],hit[N];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= k;i ++){
        cin>>num[i]>>hit[i];
    }
    for(int i = 1;i <= k;i ++){
        for(int j = n;j >= num[i];j --){
            for(int t = m-1;t >= hit[i];t --){
                f[j][t] = max(f[j][t],f[j-num[i]][t-hit[i]+1]);
            }
        }
    }
    cout<<f[m][t-1]<<' ';
    int maxm = m;
    for(int t = 0;t <= m;t ++){
        if(f[m][t] == f[m][t-1]){
            maxm = min(maxm,t);
        }
    }
    cout<<m - maxm<<endl;
    return 0;
}