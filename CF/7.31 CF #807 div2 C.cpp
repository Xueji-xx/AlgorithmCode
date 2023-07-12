#include<iostream>
using namespace std;
#define int long long
typedef pair<int,int> PII;


void solve(){
    int n,c,q;
    cin>>n>>c>>q;
    string s;
    cin>>s;
    PII a[n+5];
    for(int i = 0;i < c;i ++){
        cin>>a[i].first >> a[i].second;
    }
    while(q--){
        int x;
        cin>>x;
        while(x > s.length()){
            int cnt = 0;
            x -= s.length();
            while(x - (a[cnt].second - a[cnt].first + 1) > 0){
                x -= (a[cnt].second - a[cnt].first + 1);
                cnt++;
            }
            x += (a[cnt].first-1);
        }
        cout<<'*'<<x<<endl;
        cout<<s[x-1]<<endl;
    }

}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}