#include<iostream>
using namespace std;

void solve(){
    int a[4];
    for(int i = 0;i < 4;i ++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i = 0;i < 4;i ++){
        if(a[i] > a[0])ans++;
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