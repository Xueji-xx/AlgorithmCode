#include <iostream>
using namespace std;
#define int long long
int n;
int a[300050];

bool check(int odd,int even,int maxm){
    for(int i = 1;i <= n;i ++){
        if(a[i] < maxm){
            int x = maxm - a[i];
            if(x / 2 <= even){
                even -= x/2;
                odd -= x % 2;
            }
            else{
                x -= even*2;
                even = 0;
                odd -= x;
            }
        }
        if(odd < 0)return false;
    }
    return true;
}

void solve(){
    cin>>n;
    int maxm = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        maxm = max(maxm,a[i]);
    }
    int l = 0,r = 1e18+50;
    int ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid - mid/2,mid / 2,maxm) || check(mid - mid/2,mid / 2,maxm + 1)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid +1;
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}