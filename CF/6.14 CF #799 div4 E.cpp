#include<iostream>
#include<map>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    map<int,vector<int>>a;
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        sum += x;
        a[x].push_back(i);
    }
    if(sum < k){
        cout<<-1<<endl;
        return;
    }
    int t[n+50] = {0};
    for(auto i:a[1]){
        t[++t[0]] = min(abs(i-1),abs(i-n))+1;
    }
    sort(t+1,t + t[0]+1);
    int x = sum - k;
    int ans = 0;
    for(int i = 1;i <= sum-k;i ++){
        cout<<t[i]<<" ";
        ans += t[i];
    }
    //cout<<endl;
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}