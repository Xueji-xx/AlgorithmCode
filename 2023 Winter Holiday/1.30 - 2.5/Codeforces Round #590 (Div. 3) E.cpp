#include <iostream>
using namespace std;
#define int long long
const int N = 2e5+50;

int ans[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x[m+10];
    for(int i = 1;i <= m;i ++)cin>>x[i];
    for(int i = 1;i < m;i ++){
        int a = x[i];
        int b = x[i+1];
        if(a == b)continue;
        if(a > b)swap(a,b);//保证 a 在 b 的左侧
        // [1 , a-1]  [b+1, n]   b-a
        if(a - 1 >= 1){
            ans[1] += b-a;
            ans[a] -= b-a;
        }
        if(n >= b+1){
            ans[b+1] += b-a;
            ans[n+1] -= b-a;
        }
        // [a+1,b-1] b - a - 1
        if(b-1 >= a+1){
            ans[a+1] += b-a-1;
            ans[b] -= b-a-1;
        }
        //[a,a] b-1
        ans[a] += b-1;
        ans[a+1] -= b-1;
        //[b,b] a
        ans[b] += a;
        ans[b+1] -= a;
    }
    for(int i = 1;i <= n;i ++)ans[i] += ans[i-1];
    for(int i = 1;i <= n;i ++)cout<<ans[i]<<' ';
    return 0;
}