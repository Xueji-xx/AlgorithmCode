#include <iostream>
using namespace std;
#define int long long
//不会手搓线段树怎么办a

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n+10];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    while(m --){
        int op;
        int l,r;
        cin>>op>>l>>r;
        if(op == 1){
            for(int i = l;i <= r;i ++){
                if(a[i] >= 10)a[i] = 2 * a[i] / 3;
            }
        }
        else if(op == 2){
            int cnt = 0;
            for(int i = l;i <= r;i ++){
                if(a[i] < 100)cnt++;
            }
            cout<<cnt<<endl;
        }
        else if(op == 3){
            int sum = 0;
            for(int i = l;i <= r;i ++){
                sum += a[i];
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}