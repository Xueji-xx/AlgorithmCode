#include<iostream>
#include<string.h>
using namespace std;
#define int long long

void solve(){
    int n,k,b,s;
    cin>>n>>k>>b>>s;
    int a[n+5];
    memset(a,0,sizeof a);
    int t;
    t = s / k;
    if(t < b){
        cout<<-1<<endl;
        return;
    }
    a[n] = max((int)0,min(s,(b+1)*k-1));
    t = s - a[n];
    for(int i = n-1;i >= 1;i --){
        if(t >= k-1)a[i] = k-1,t -= k-1;
        else{
            a[i] = t;
            t = 0;
            break;
        }
    }
    if(t > 0){
        cout<<-1<<endl;
        return;
    }
    for(int i = 1;i <= n;i ++)cout<<a[i]<<' ';
    cout<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}