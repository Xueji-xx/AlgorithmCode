#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    string s,t;
    cin>>s>>t;
    vector<int> a[30];
    for(int i = 0;i < s.length();i ++){
        a[s[i] - 'a'].push_back(i);
    }
    int ans = 1;
    int cur = -1;
    for(int i = 0;i < t.length();i ++){
        int x = t[i] - 'a';
        if(!a[x].size()){
            ans = -1;
            break;
        }
        int pos = upper_bound(a[x].begin(),a[x].end(),cur) - a[x].begin();
        if(pos == a[x].size()){
            ans++;
            pos = 0;
        }
        cur = a[x][pos];
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}