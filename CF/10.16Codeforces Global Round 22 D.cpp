#include<iostream>
#include<vector>
using namespace std;
#define endl '\n'

int n;
void solve(){
    cin>>n;
    int k = 0;
    vector<int> b(n+5);
    vector nxt(n + 2, vector<int>());
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        k += x>i;
        nxt[x].push_back(i);
    }
    cout<<k<<endl;
    for(int i = nxt[0].size() ? 0: n+1;nxt[i].size();i = nxt[i].back()){
        for(auto &x : nxt[i]){
            if(nxt[x].size()){
                swap(x,nxt[i].back());
            }
        }
        for(auto &x:nxt[i])cout<<x<<' ';
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}