#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+50;

struct node{
    int l,r;
    int v;
}q[N];
int ans[N];
int cnt;

void dfs(int l,int r){
    if(l > r)return;
    q[++cnt].l = l;
    q[cnt].r = r;
    q[cnt].v = (r - l + 1);
    int mid = l + r >> 1;
    dfs(l,mid-1);
    dfs(mid+1,r);
}

bool cmp(node a,node b){
    if(a.v == b.v)return a.l < b.l;
    return a.v > b.v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cnt = 0;
        int n;
        cin>>n;
        dfs(1,n);
        sort(q+1,q+1+cnt,cmp);
        for(int i = 1;i <= n;i ++){
            int mid = (q[i].l + q[i].r) / 2;
            ans[mid] = i;
        }
        for(int i = 1;i <= n;i ++)cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}