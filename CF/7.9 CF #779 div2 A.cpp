#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[200] = {0};
    string s;
    cin>>s;
    int ans = 0;
    if(n == 1 && s[0] == '0'){
        cout<<1<<endl;
        return;
    }
    for(int i = 0;i < n;i ++){
        if(s[i] == '0')a[++a[0]] = i;
    }
    for(int i = 1;i <= a[0]-1;i ++){
        if(a[i+1] - a[i] <= 2)ans += 2 - (a[i+1] - a[i]) + 1;
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