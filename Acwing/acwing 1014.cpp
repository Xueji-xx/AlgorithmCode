#include<iostream>
using namespace std;

const int N = 1010;
int f[N][2],n,ans,h[N];


int main(){
    cin>>n;
    for(int i = 1;i <= n;i ++){
        f[i][0] = 1;
        cin>>a[i];
        for(int j = 1;j < i;j ++){
            if(h[i] > h[j])f[i][0] = max(f[i][0],f[j][0] + 1);
        }
    }
    for(int i = n;i >= 1;i --){
        for(int j = n;j > i;j --){
            if(h[i] > h[j])f[i][1] = max(f[i][1],f[j][1] + 1);
        }
        ans = max(ans,f[i][0] + f[i][1] - 1);
    }
    cout<<ans<<endl;
    return 0;
}