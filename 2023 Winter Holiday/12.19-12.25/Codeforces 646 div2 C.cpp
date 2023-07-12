#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int tree[1500];

signed main(){
    int t;
    cin>>t;
    while(t--){
        memset(tree,0,sizeof tree);
        int n,x;
        cin>>n>>x;
        for(int i = 1;i < n;i ++){
            int u,v;
            cin>>u>>v;
            tree[u]++;//.push_back(v)
            tree[v]++;
        }
        if(n == 1 || tree[x] == 1|| n % 2 == 0){
            cout<<"Ayush"<<endl;
        }
        else cout<<"Ashish"<<endl;
    }
    return 0;
}