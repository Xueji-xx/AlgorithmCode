#include <iostream>
#include <map>
using namespace std;
#define int long long
const int N = 1500;

void solve(){
    int n;
    cin >> n;
    int a[n+50];
    for (int i = 1; i <= n; i++ ) cin >> a[i];
        map<int, int> mp, mpp[N];
    for (int i = 1; i <= n; i++ ) {
        if(mp[a[i]]){
            cout<<"NO"<<endl;
            return;
        }
        mp[a[i]]++ ;
        for (int j = 2; j <= n; j++ ) 
            mpp[j][a[i] % j]++ ;
    }
    for (int i = 2; i <= 50; i++ ) {
        bool flag = false;
        for (int j = 0; j < i; j++ ) 
            if(mpp[i][j] < 2) 
                flag = true;
        if(!flag){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}