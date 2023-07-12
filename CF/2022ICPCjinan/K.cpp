#include <iostream>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        int vis[n+10] = {0};
        for(int i = 1;i <= n;i ++){
            int x;
            cin>>x;
            if(vis[x+1] == 0){
                ans++;
            }
            vis[x] = 1;
        }
        cout<<ans<<endl;
    }
    return 0;  
}