#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = '?' + s;
    int a = 0,b = 0;
    for(int i = 1;i <= 2 * n;i ++){
        if(s[i] == '1')a++;
        else b++;
    }
    if((a & 1) || (b & 1)){
        cout<<-1<<endl;
        return;
    }
    vector<int> v;
    for(int i = 1,cur = 0;i <= 2 * n;i += 2){
        if(s[i] != s[i+1]){
            if(s[i] - '0' == cur){
                v.push_back(i);
                cur ^= 1;
            }
            else{
                v.push_back(i+1);
                cur ^= 1;
            }
        }
    }
    cout<<v.size()<<endl;
    for(auto i : v)cout<<i<<' ';
    cout<<endl;
    for(int i = 1;i <= 2 * n;i += 2)cout<<i<<' ';
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}