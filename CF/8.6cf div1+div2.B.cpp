#include<iostream>
using namespace std;
typedef pair<int,int> PII;



void solve(){
    int n,x;
    cin>>n>>x;
    int a[n+5] = {0};
    PII p[n+5];
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 0;i < n;i ++){
        p[i].first = a[i] - x;
        p[i].second = a[i] + x;
    }
    int ans = 0;
    PII s = p[0];
    for(int i = 1;i < n;i ++){
        if(s.first > p[i].second || s.second < p[i].first){
            ans++;
            s = p[i];
            continue;
        }
        else if(p[i].first > s.first)s.first = p[i].first;
        else if(p[i].second < s.second)s.second = p[i].second;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}