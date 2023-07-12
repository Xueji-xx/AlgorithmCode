#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    for(int i = 0;i < n;i ++)cin>>a[i];
    vector<int> cnt(n+10);
    for(int i = 0;i < n;i ++)cnt[a[i]]++;
    vector<int> ans;
    int i = 0;
    while(i < n){
        int mex = 0;
        while(cnt[mex])mex++;
        vector<bool> vis(n+10);
        int x = 0;
        while(i < n){
            if(a[i] < mex && !vis[a[i]]){
                vis[a[i]] = true;
                x++;
            }
            cnt[a[i]]--;
            i++;
            if(x == mex)break;
        }
        ans.push_back(mex);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';
    cout<<endl;
}

int main(){
    int T_T;
    cin>>T_T;
    while(T_T--)solve();
    system("pause");
    return 0;
}