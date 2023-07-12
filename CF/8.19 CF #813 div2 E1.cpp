#include<iostream>
#include<string.h>
using namespace std;
const int N = 2e5+10;
int a[N];
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        memset(a,0,sizeof a);
        int len = r - l + 1;
        int ans = len * (len-1) * (len-2) / 6;
        for(int i = l;i < r;i ++){
            for(int j = i * 2;j <= r;j += i)a[j]++;
        }
        for(int i = l+2;i <= r;i ++){
            int res = a[i] * (a[i] - 1)/ 2;
            ans -= res;
            if(i % 3 == 0){
                if(i % 2 == 0 && i / 2 >= l)ans--;
                if(i % 5 == 0 && i / 5 * 2 >= l)ans--;
            }
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}