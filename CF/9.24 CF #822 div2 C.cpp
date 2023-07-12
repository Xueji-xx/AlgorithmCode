#include<iostream>
using namespace std;
const int N = 1e6+50;
#define int long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = '*' + s;
    int ans = 0;
    bool del[N],pre[N];
    for(int i = 1;i <= n;i ++){
        del[i] = false;
        pre[i] = false;
    }
    for(int i = 1;i <= n;i ++){
        if(s[i] == '0')del[i] = true;
        else pre[i] = true;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = i;j <= n;j += i){
            if(del[j])ans += i,del[j] = false;
            else if(pre[j])break;
        }
    }
    cout<<ans<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}