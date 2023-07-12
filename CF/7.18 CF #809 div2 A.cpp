#include<iostream>
#include<string.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int cnt[m+5];
    memset(cnt,0,sizeof cnt);
    for(int i = 1;i <= n;i ++){
        int x;cin>>x;
        cnt[x]++;
    }
    int s[60];
    memset(s,0,sizeof s);
    for(int i = 1;i <= m;i ++){
        if(cnt[i] >= 2){
            s[i] = 1;s[m+1-i] = 1;
        }
        else if(cnt[i] == 1){
            int x = min(i,m-i+1);
            if(s[x] == 1)s[max(i,m-i+1)] = 1;
            else s[x] = 1;
        }
    }
    for(int i = 1;i <= m;i ++){
        if(s[i])cout<<'A';
        else if(!s[i]) cout<<'B';
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
