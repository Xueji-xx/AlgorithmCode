#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 1e6+500;
struct node{
    int x,l,r,max;
}tr[N*4];

int a[N],b[N],be[N];

void update(node &u,node &l,node &r){
    u.max = max(l.max,r.max);
}

void update(int u){
    update(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r){
    int mid = l + r >> 1;
    if(l == r){
        tr[u] = {a[l],l,l,a[l]};
    }
    else{
        tr[u].l = l;
        tr[u].r = r;
        build(u << 1,l,mid);
        build(u << 1 | 1,mid+1,r);
        update(u);
    }
}

int get(int u,int l,int r){
    int res = 0;
    if(tr[u].l >= l && tr[u].r <= r)return tr[u].max;
    int mid = tr[u].l + tr[u].r >> 1;
    if(mid >= l){
        res = max(res,get(u << 1,l,r));
    }
    if(mid < r){
        res = max(res,get(u << 1 | 1,l,r));
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    bool flag = false;
    vector<int> cnt;
    map<int,vector<int>> q;
    map<int,int> p;
    for(int i = 1;i <= n;i ++){
        cin>>be[i];
    }
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        if(be[i] < a[i])flag = true;
        if(be[i] != a[i])q[a[i]].push_back(i);
    }
    build(1,1,n);
    int m;
    cin>>m;
    for(int i = 1;i <= m;i ++){
        cin>>b[i];
        if(!p[b[i]]){
            cnt.push_back(b[i]);
        }
        p[b[i]] ++;
    }
    for(int i = 1;i <= n;i ++){
        if(!p[a[i]] && a[i] != be[i]){
            flag = true;
        }
    }
    if(flag){
        cout<<"NO"<<endl;
        return;
    }

    for(int i = 0;i < cnt.size();i ++){
        int time = p[cnt[i]];
        int num = 1;
        if(q[cnt[i]].size() == 0)continue;
        for(int k = 0;k < q[cnt[i]].size() - 1;k ++){
            int l = q[cnt[i]][k];
            int r = q[cnt[i]][k+1];
            if(get(1,l,r) > cnt[i]){
                num++;
            }
        }
        if(num > time)flag = true;
    }
    if(flag){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}