#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 5e5+10;

vector<int> v[N];
int cnt[N];//节点个数
int val[N];//价值

void dfs(int now,int root){
    int maxm = 0;
    for(auto x:v[now]){
        if(x == root)continue;
        dfs(x,now);
        cnt[now] += cnt[x] + 1;
        maxm = max(maxm,val[x]);
    }
    val[now] = maxm + cnt[now] + 1;
}


void solve(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        v[i].clear();
        val[i] = 0;
        cnt[i] = 0;
    }
    for(int i = 1;i <= n-1;i ++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
	dfs(1,0);
    cout<<val[1]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}