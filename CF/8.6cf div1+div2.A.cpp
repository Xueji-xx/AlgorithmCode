#include<iostream>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int j = m-1;
    for(int i = n-1;i >= n-m+1 && j >= 0;i --){
        if(a[i] != b[j]){
            cout<<"NO"<<endl;
            return;
        }
        else j--;
    }
    for(int i = 0;i < n-m+1;i ++){
        if(a[i] == b[0]){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}