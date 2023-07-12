#include<iostream>
#include<string.h>
using namespace std;
const int N = 2e5+50;
bool vis[N];

void solve(){
    int n;
    cin>>n;
    cout<<2<<endl;
    memset(vis,false,sizeof vis);
    for(int i = 1;i <= n;i ++){
        if(vis[i])continue;
        for(int j = i;j <= n;j *= 2){
            vis[j] = true;
            cout<<j<<" ";
        }
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