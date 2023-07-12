#include <iostream>
using namespace std;
#define int long long

int pow2[40];
int cnt[40]; 
void init(){
    pow2[0]=1;
    for(int i=1;i<=31;i++)
        pow2[i]=pow2[i-1]*2;
        return;
}

void solve(){
    int n;
    cin>>n;
    for(int i = 31;i > 0;i --)cnt[i] = 0;
    for(int i = 31;i > 0;i --){
        if(n>=pow2[i]){
            cnt[i]++;
            n-=(pow2[i]);
            cnt[1]++;
        }
    }
    if(n % 2)cnt[1]++;
    //nunhehhehaaaaaaaaaaaaaaahahaahahahahahahaahaahaaaha
    //nunhehhehahaahahahahahahaahaahahahahha
    cout<<"nunhehhe";
    for(int i = 31;i > 0;i --){
        for(int j = 0;j < cnt[i];j ++)cout<<'h';
        cout<<'a';
    }
    cout<<endl;
}

signed main(){
    init();
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}