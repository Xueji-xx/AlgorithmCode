#include<iostream>
using namespace std;
const int N = 2e6+50;
int a[N];
int v[N];
int f[N];
int ans = N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++){
        v[i] = 1;
        int t = i;
        int p = a[i];
        while(f[p] != i){
            if(f[p] != 0 && f[p] < i)break;
            v[p] = v[t] + 1;
            f[t] = i;
            t = p;
            p = a[t];
        }
    }
    for(int i = 1;i <= n;i ++)cout<<v[i]<<' ';
    system("pause");
    return 0;
}