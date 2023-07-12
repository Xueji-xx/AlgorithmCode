#include<iostream>
using namespace std;
int n,a,b;
int ans = 99999;
int k[300];
bool vis[500];
void dfs(int a,int cnt){
    if(a == b){
        ans = min(ans,cnt);
        return;
    }
    if(a < 0 || a > n || cnt > ans)return;
    if(!vis[a]){
        vis[a] = true;
        dfs(a+k[a],cnt+1);
        dfs(a-k[a],cnt+1);
        vis[a] = false;
    }
}

int main(){
    cin>>n>>a>>b;
    for(int i = 1;i <= n;i ++){
        cin>>k[i];
    }
    dfs(a,0);
    if(ans == 99999)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}