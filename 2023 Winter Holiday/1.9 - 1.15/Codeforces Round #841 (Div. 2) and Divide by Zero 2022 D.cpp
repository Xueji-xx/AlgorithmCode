#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int N = 1e6+50;

int now[N];
vector<int> a[N];
int n,m;

bool check(int mid){
    
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(a[i][j] >= mid)now[j]++;
            else now[j] = 0;
        }
        int s = 0;
        for(int j = 1;j <= m;j ++){
            if(now[j] >= mid){
                s++;
            }
            else s = 0;
            if(s >= mid)return true;
        }
    }
    return false;
}

void solve(){
    cin>>n>>m;
    for(int i = 1;i <= n;i ++){
        a[i].clear();
        a[i].push_back(0);
        for(int j = 1;j <= m;j ++){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    int l = 1,r = min(n,m);
    while(l <= r){
        memset(now,0,sizeof now);
        int mid = l + r >> 1;
        if(check(mid)){
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<l-1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}