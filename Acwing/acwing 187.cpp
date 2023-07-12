#include<iostream>
using namespace std;
const int N = 100;

int a[N];
int up[N],down[N];
int res;
int n;

void dfs(int u,int s_up,int s_down){
    if(s_up + s_down >= res)return;
    if(u == n){
        res = s_up + s_down;
        return;
    }

    int k = 0;
    while(k <= s_up && up[k] >= a[u])k++;
    int t = up[k];
    up[k] = a[u];
    if(k >= s_up)dfs(u+1,s_up+1,s_down);
    else dfs(u+1,s_up,s_down);
    up[k] = t;

    k = 0;
    while(k < s_down && up[k] <= a[u])k++;
    t = down[k];
    down[k] = a[u];
    if(k >= s_down)dfs(u+1,s_up,s_down+1);
    else dfs(u+1,s_up,s_down);
    down[k] = t;
}


int main(){
    while(cin>>n && n){
        int a[n+10] = {0};
        for(int i = 0;i < n;i ++)cin>>a[i];
        res = n;
        dfs(0,0,0);
        cout<<res<<endl;
    }
    return 0;
}