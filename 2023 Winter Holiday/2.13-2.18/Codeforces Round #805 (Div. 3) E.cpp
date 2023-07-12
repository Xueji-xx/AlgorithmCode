#include <iostream>
#include <string.h>
using namespace std;
const int N = 2e5+50;

int p[N],sz[N];

int find(int x){
    if(x != p[x]){
        p[x] = find(p[x]);
    }
    return p[x];
}

void solve(){
    int n;
    cin>>n;
    int cnt[N];
    memset(cnt,0,sizeof cnt);
    for(int i = 1;i <= n;i ++){
        p[i] = i;
        sz[i] = 1;
    }
    bool flag = true;
    for(int i = 1;i <= n;i ++){
        int a,b;
        cin>>a>>b;
        cnt[a]++,cnt[b]++;
        if(cnt[a] > 2 || cnt[b] > 2){
            flag = false;
        }
        a = find(a);
        b = find(b);
        if(a == b && sz[a] & 1){
            flag = false;
        }
        else if(a != b){
            p[a] = b;
            sz[b] += sz[a];
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}