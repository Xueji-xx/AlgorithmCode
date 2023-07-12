#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define int long long
#define MAXN 1005

map<string,int> mp;

int cnt[6], cnt1[6];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        string s;
        for(int j = 1;j <= 5;j ++){
            cin>>s;
            mp[s] = 1;
        }
    }
    int m;
    cin>>m;
    for(int i = 1;i <= m;i ++){
        string s;
        int x;
        cin>>s>>x;
        cnt[x]++;
        if(mp[s] == 1)cnt1[x]++;
    }
    int minn = cnt[1];
    for(int i = 1;i <= 5;i ++)minn = min(minn,cnt[i]);
    int sum = 0;
    for(int i = 1;i <= 5;i ++)sum += cnt1[i];
    cout<<min(minn,sum);
    return 0;
}