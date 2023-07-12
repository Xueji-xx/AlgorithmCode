#include<iostream>
#include<string.h>
using namespace std;

void solve(){
    int n,c;
    cin>>n>>c;
    int a[150];
    memset(a,0,sizeof a);
    for(int i = 0;i < n;i ++){
        int x;
        cin>>x;
        a[x]++;
    }
    int ans = n;
    for(int x = 1;x <= 100;x ++){
        if(a[x] == 0)continue;
        else{
            if(a[x] > c){
                ans += c;
                ans -= a[x];
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}