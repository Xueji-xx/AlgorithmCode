#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int v[n+10];
        int f[30000];
        for(int i = 1;i <= n;i ++)cin>>v[i];
        sort(v+1,v+1+n);
        int m = v[n],res = 0;
        memset(f,0,sizeof f);
        f[0] = true;
        for(int i = 1;i <= n;i ++){
            if(f[v[i]])continue;
            res++;
            for(int j = v[i];j <= m;j ++){
                f[j] |= f[j - v[i]];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}