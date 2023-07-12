#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct{
    int first;
    int second;
    int idx;
}PII;

bool cmp(PII a,PII b){
    if(a.second == b.second)return a.first < b.first;
    else return a.second < b.second;
}

void solve(){
    int n;
    cin>>n;
    PII a[n];
    for(int i = 0;i < n;i ++)cin>>a[i].first;
    string s;
    cin>>s;
    for(int i = 0;i < n;i ++){
        a[i].second = s[i]-'0';
        a[i].idx = i;
    }
    sort(a,a+n,cmp);
    int x = 1;
    vector<int> ans(n);
    for(int i = 0;i < n;i ++)ans[a[i].idx] = x++;
    for(int i = 0;i < n;i ++)cout<<ans[i]<<' ';
    cout<<endl;
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