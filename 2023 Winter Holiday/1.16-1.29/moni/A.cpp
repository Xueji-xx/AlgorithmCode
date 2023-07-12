#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define int long long

vector<int> a[50];

signed main(){
    string s,t;
    cin>>s>>t;
    s = '1' + s;
    t = '1' + t;

    for(int i = 1;i < s.length();i ++){
        a[s[i] - 'a'].push_back(i);
    }
    int ans = 1;
    int pos = 0;
    for(int i = 1;i < t.length();i ++){
        int p = t[i] - 'a';
        if(*(a[p].end()-1) <= pos){
            ans++;
            pos = *(a[p].begin());
        }
        else{
            auto x = *lower_bound(a[p].begin(),a[p].end(),pos+1);
            pos = x;
        }
    }
    cout<<ans<<endl;
    return 0;
}
