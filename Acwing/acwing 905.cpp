#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e9+7;
#define l first
#define r second
typedef pair<int,int> PII;

int main(){
    int n;
    cin>>n;
    PII a[n+5];
    for(int i = 0;i < n;i ++){
        cin>>a[i].l>>a[i].r;
    }
    sort(a,a+n);
    int r = -N;
    int ans = 0;
    for(int i = 0;i < n;i ++){
        if(a[i].l > r){
            ans++;
            r = a[i].r;
        }
        else r = min(a[i].r,r);
    }
    cout<<ans<<endl;
    return 0;
}