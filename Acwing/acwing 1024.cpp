#include<iostream>
using namespace std;
int w[50];
int f[20010];
int main(){
    int v;
    cin>>v;
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>v[i];
    for(int i = 1;i <= n;i ++){
        for(int j = m;j >= v[i];j ++){
            f[j] = max(f[j],f[j - v[i]]+v[i]);
        }
    }
    cout<<m - f[m]<<endl;
    return 0;
}