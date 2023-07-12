#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1010;

string ans[N];
set<char> se;
int f[N];
string s;

void solve(int len){
    se.clear();
    for(int i = len - 1;i >= 0;i --){
        if(se.count(s[i]) == 0)f[s[i]] = se.size();
        se.insert(s[i]);
    }
}

int main(){
    int n;
    cin>>n;
    
    cin>>s;
    for(int len = 1;len <= n;len ++){
        solve(len);\
        for(int j = 0;j < len;j ++){
            ans[len] += (f[s[j]] + 'a');
        }
    }
    sort(ans + 1,ans + 1 + n);
    cout<<ans[n]<<endl;
    return 0;
}