#include<iostream>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int maxm = 0;
    for(int i = 0;i < n;i ++){
        int y;
        cin>>y;
        y |= k;
        maxm = max(maxm,y);
    }
    cout<<maxm<<endl;
}



int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}