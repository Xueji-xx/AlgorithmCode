#include<iostream>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    for(int i = 0;i < n;i ++){
        if(a[i] > b[i]){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i] < b[i] && b[i] > b[(i +1)% n] + 1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}