#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 2e5+10;
int n;  
int a[10],b[10],x;

void solve(){
    cin>>n;
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    for(int i = 1; i <= n; i++)cin>>x, a[x]++;
    for(int i = 1; i <= n; i++)cin>>x, b[x]++;
    int flag = 0;
    for(int i = 1; i <= 6; i++){
        if(a[i] > 1 || b[i] > 1)flag = 1;
    }
    if(flag)cout<<"Win!\n";
    else cout<<"Just a game of chance.\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;  
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}