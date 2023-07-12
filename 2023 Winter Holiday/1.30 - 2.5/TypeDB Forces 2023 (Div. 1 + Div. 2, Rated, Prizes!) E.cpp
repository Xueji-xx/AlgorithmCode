#include <iostream>
#include <set>
using namespace std;
#define int long long

void solve(){
    int n,k,x;
    cin>>n>>k>>x;
    int xor_sum = (k % 2 == 0 ? 0 : x);
    for(int i = 1;i <= n;i ++)xor_sum ^= i;

    int tot = 0;
    for(int i = 1;i <= n;i ++){
        if((x & i) > x / 2)tot++;
    }
    if(xor_sum != 0 || tot < k){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if(k == 1){
        cout<<n<<' ';
        for(int i = 1;i <= n;i ++){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    else{
        int cnt = 0;
        set<int> s;
        for(int i = 1;i <= n;i ++)s.insert(i);
        if(s.count(x)){
            cout<<1<<' '<<x<<endl;
            cnt++;
            s.erase(x);
        }
        for(int i = 1;i <= n;i ++){
            if(!s.count(i) || !s.count(x ^ i))continue;
            if(cnt == k-1)break;
            cnt++;
            cout<<2<<' '<<i<<' '<<(x ^ i)<<endl;
            s.erase(i);
            s.erase(x ^ i);
        }
        cout<<s.size()<<' ';
        for(int i : s)cout<<i<<' ';
        cout<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}