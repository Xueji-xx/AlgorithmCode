#include <iostream>
#include <vector>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> a(k+10),vis(k+10);
        a.clear();vis.clear();
        for(int i = 0;i < k;i ++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        int cnt = 0;
        bool flag = true;
        for(int i = k,j = 0;i;i --){
            while(!vis[i]){
                vis[a[j++]] = true;
                cnt++;
            }
            cnt--;
            if(cnt > n*m - 4){
                flag = false;
                break;
            }
        }
        cout<<(flag ? "YA" : "TIDAK")<<endl;
    }
    return 0;
}