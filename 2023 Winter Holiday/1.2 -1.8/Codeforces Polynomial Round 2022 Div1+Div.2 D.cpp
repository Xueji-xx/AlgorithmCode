//1600
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(n,vector<int>(k));
    vector<int> cnt(n);
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < k;j ++){
            cin>>a[i][j];
        }
    }
    for(int i = 0;i < n;i ++){
        cnt[i] = accumulate(a[i].begin(),a[i].end(),0);
    }
    int sum = accumulate(cnt.begin(),cnt.end(),0);
    if(sum % n){
        cout<<-1<<endl;
        return;
    }
    sum /= n;
    int ans = 0;
    for(int i = 0;i < n;i ++)ans += abs(cnt[i] - sum);
    cout<<ans/2<<endl;
    vector<int> idx(n);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int i,int j){return cnt[i] < cnt[j];});
    int l = 0,r = n-1;
    while(l < r){
        int i = idx[l],j = idx[r];
        auto &a1 = a[i], &b1 = a[j];
        for(int p = 0;p < k && cnt[i] != sum && cnt[j] != sum;p ++){
            if(a1[p] == 0 && b1[p] == 1){
                swap(a1[p],b1[p]);
                cnt[i]++;
                cnt[j]--;
                cout<<i+1<<' '<<j+1<<' '<<p+1<<endl;
            }
        }
        if(cnt[i] == sum)l++;
        if(cnt[j] == sum)r--;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}