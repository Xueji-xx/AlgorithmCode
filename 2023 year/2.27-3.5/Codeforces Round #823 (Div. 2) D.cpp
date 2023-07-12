#include <iostream>
#include <map>
using namespace std;

#define pcc pair<char,char>

map<pcc,int> mp;

void solve(){
    int n;
    cin>>n;
    string s,s2;
    cin>>s>>s2;
    mp.clear();
    for(int i = 0;i < n;i ++){
        char a = s[i];
        char b = s2[n-i-1];
        if(a > b){
            swap(a,b);
        }
        mp[{a,b}]++;
    }
    int sum = 0;
    bool flag = true;
    for(auto p : mp){
        if(p.second % 2 == 0)continue;
        pcc tmp = p.first;
        if(p.first.first != p.first.second){
            flag = false;
            break;
        }
        sum++;
    }
    if(sum < 2 && flag)flag = true;
    else flag = false;
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}