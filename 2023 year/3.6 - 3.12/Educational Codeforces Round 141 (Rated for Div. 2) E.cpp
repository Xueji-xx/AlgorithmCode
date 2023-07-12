#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6+50;
int a[N],b[N];
int d[N];

void solve(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i ++){
        cin>>a[i];
        d[i] = 0;
    }
    d[n] = 0;
    d[n+1] = 0;
    for(int i = 0;i < n;i ++){
        cin>>b[i];
    }
    for(int i = 0;i < n;i ++){
        if(a[i] > b[i]){
            d[b[i]]++;
            d[a[i]]--;
        }
    }
    for(int i = 1;i <= n;i ++){
        d[i] += d[i-1];
    }
    vector<int> ans;
    for(int k = 1;k <= n;k ++){
        bool flag = true;
        for(int i = k;i <= n;i += k){
            if(d[i]){
                flag = false;
                break;
            }
        }
        if(flag)ans.push_back(k);
    }
    cout<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i<<" \n"[i == ans.back()];
    }
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}