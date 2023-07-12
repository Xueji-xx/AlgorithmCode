#include <iostream>
using namespace std;
    
void solve(){
    int n;
    cin>>n;
    int a[n+5];
    int cnt = 0;
    int cnt1 = 0,cnt_1 = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        if(i % 2 == 0){
            if(a[i] == a[i-1])cnt+=1;
            else cnt+=2;
        }
        if(cnt1 == 1)cnt1++;
        else cnt_1++;
    }
    if((cnt1 - cnt_1) & 1){
        cout<<-1<<endl;
        return;
    }
    cout<<cnt<<endl;
    for(int i = 1;i <= n;i ++){
        if(a[i] == a[i+1]){
            cout<<i<<' '<<i+1<<endl;
            i ++;
        }
        else{
            cout<<i<<' '<<i<<endl;
            cout<<i+1<<' '<<i+1<<endl;
            i++;
        }
    }
}
    
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}