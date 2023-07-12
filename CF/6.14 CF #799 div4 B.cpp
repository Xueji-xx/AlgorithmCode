#include<iostream>
#include<map>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int> a;
    for(int i = 0;i < n;i ++){
        int x;
        cin>>x;
        a[x]++;
    }
    int sum = 0;
    for(auto i:a){
        if(i.second > 1){
            sum += i.second-1;
        }
    }
    if(sum & 1)cout<<n-sum-1<<endl;
    else cout<<n - sum<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}