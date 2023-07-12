#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5+50;
int a[N];
int n,m;

bool check(int mid){
    int l = mid,r = n;
    while(l < r){
        if(a[r] > m - a[l])return false;
        l++;
        if(l < r){
            if(a[l] > m - a[r])return false;
            r --;
        }
    }
    return true;
}

signed main(){
    cin>>n>>m;
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum += a[i];
    }
    sort(a+1,a+1+n,greater<int>());
 /*   for(int i = 1;i <= n;i ++)cout<<a[i]<<' ';
    cout<<endl;*/
    int l = 1,r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    int ans = sum + r;
    cout<<ans<<endl;
    return 0;
}