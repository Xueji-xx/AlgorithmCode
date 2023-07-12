#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<int>> a,tr;
int cnt;
int pos[30];

void insert(){
    int p = 0;
    for(int i = 1;i <= m;i ++){
        if(!tr[p][pos[i]])tr[p][pos[i]] = ++cnt;
        p = tr[p][pos[i]];
    }
}   

int query(int u){
    int p = 0,res = 0;
    for(int i = 1;i <= m;i ++){
        if(!tr[p][a[u][i]])break;
        res++;
        p = tr[p][a[u][i]];
    } 
    return res;
}

void solve(){
    cin>>n>>m;
    cnt = 0;
    tr = vector<vector<int>>(n * m + 10 , vector<int>(m + 10));
    a = vector<vector<int>>(n + 10 , vector<int>(m + 10));
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin>>a[i][j];
            pos[a[i][j]] = j;
        }
        insert();
    }
    for(int i = 1;i <= n;i ++){
        cout<<query(i)<<' ';
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}