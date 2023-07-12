#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 0;i < n;i ++)cin>>b[i];
    int ans = 0;
    for(int i = 29;i >= 0;i --){
        ans |= (1 << i);
        vector<int>x,y;
        for(int j = 0;j < n;j ++){
            x.push_back(ans & a[j]);
        }
        for(int j = 0;j < n;j ++){
            y.push_back(ans - (ans & b[j]));
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(x != y)ans ^= (1 << i);
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}