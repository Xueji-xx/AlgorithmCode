#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long


typedef pair<int,int> PII;
vector<PII> v1,v2;

void solve(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    v1.clear(),v2.clear();
    if(s1[0] != s2[0] || s1[n-1] != s2[n-1]){
        cout<<-1<<endl;
        return;
    }
    int l1 = 0,l2 = 0,cnt1 = 0,cnt2 = 0;
    if(s1[0] == '0')cnt1++;
    if(s2[0] == '0')cnt2++;
    for(int i = 1;i < n;i ++){
        if(s1[i] != s1[i-1]){
            if(s1[i] == '0')v1.push_back({l1,i-1});
            else cnt1++;
            l1 = i;
        }
        if(s2[i] != s2[i-1]){
            if(s2[i] == '0')v2.push_back({l2,i-1});
            else cnt2++;
            l2 = i;
        }
    }
    if(s1[n-1] == '1')v1.push_back({l1,n-1});
    else cnt1++;
    if(s2[n-1] == '1')v2.push_back({l2,n-1});
    else cnt2++;
    if(v1.size() != v2.size() || cnt1 != cnt2){
        cout<<-1<<endl;
        return;
    }
    int ans = 0;
    for(int i = 0;i < v1.size();i ++){
        ans += abs(v1[i].first - v2[i].first) + abs(v1[i].second - v2[i].second);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}