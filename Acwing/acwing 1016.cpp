#include<iostream>
using namespace std;

const int N = 1010;
int f[N];

int main(){
    int n;
    cin>>n;
    int a[n+10];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < i;j ++){
            if(a[i] > a[j])f[i] = max(f[i],f[j] + a[i]);
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i ++)res = max(f[i],res);
    cout<<res<<endl;
    return 0;
}