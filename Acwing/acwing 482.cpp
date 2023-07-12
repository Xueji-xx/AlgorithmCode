#include<iostream>
using namespace std;

int a[500];
int f_up[500],f_down[500];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    a[0] = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < i;j ++){
            if(a[j] < a[i])f_up[i] = max(f_up[i],f_up[j] + 1);
        }
    }
    a[n+1] = 0;
    for(int i = n;i >= 1;i --){
        for(int j = n + 1;j > i;j --){
            if(a[i] > a[j])f_down[i] = max(f_down[i],f_down[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i ++)res = max(res,f_up[i] + f_down[i] - 1);
    cout<<n - res<<endl;
    return 0;
}