#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
#define l first
#define r second
const int N = 1e9+7;

int main(){
    int n;
    cin>>n;
    PII a[n+5];
    for(int i = 0;i < n;i ++){
        cin>>a[i].l >> a[i].r;
    }
    sort(a,a+n);
    int ans = 0;
    int r = -N;
    for(int i = 0;i < n;i ++){
        if(a[i].l > r){
            ans++;
            r = a[i].r;
        }
        else r = min(r,a[i].r);
    }
    cout<<ans<<endl;
    return 0;
}