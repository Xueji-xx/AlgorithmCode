#include<iostream>
using namespace std;

void solve(){
    int l,r,k;
    cin>>l>>r>>k;
    int cnt1 = 0,cnt0 = 0;
    if(l == r && l != 1)cout<<"YES"<<endl;
    else if(l == r && l == 1)cout<<"NO"<<endl;
    else{
        if(r & 1){
            if((r - l)/2+1 > k)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else{
            if(l & 1){
                if((r - l)/2+1 > k)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else{
                if((r - l)/2 > k)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}