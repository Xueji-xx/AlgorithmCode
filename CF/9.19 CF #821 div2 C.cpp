#include<iostream>
using namespace std;
typedef pair<int,int> PII;

void solve(){
    int n;
    PII ans[n+5];
    cin>>n;
    int a[n+5];
    int odd = 0,even = 0;
    for(int i = 0;i < n;i ++){
        cin>>a[i];
        if(a[i] & 1)odd++;
        else even++;
    }
    bool flag =false;
    int cnt = 0;
    if(a[0] & 1){
        if(a[n-1] & 1){
            flag = true;
            for(int i = 1;i < n;i ++){
                if(a[i]%2 == 0){
                    ans[cnt++] = {i+1,n};
                    a[n-1] = a[i];
                    break;
                }
            }
        }
        for(int i = 1;i < n;i ++){
            if(a[i] % 2 == 0)ans[cnt++] = {i+1,1};
            else{
                ans[cnt++] = {i+1,n};
            }
        }
    }
    else{
        if(a[n-1] % 2 == 0){
            flag = true;
            for(int i = 1;i < n;i ++){
                if(a[i] & 1){
                    ans[cnt++] = {i+1,n};
                    a[n-1] = a[i];
                    break;
                }
            }
        }
        for(int i = 1;i < n;i ++){
            if(a[i] & 1)ans[cnt++] = {i+1,1};
            else{
                ans[cnt++] = {i+1,n};
            }
        }
    }
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    if(flag)cout<<n<<endl;
    else cout<<n-1<<endl;
    for(int i = 0;i < cnt;i ++)cout<<ans[i].first<<' '<<ans[i].second<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}