#include<iostream>
using namespace std;


void solve(){
    string s;
    cin>>s;
    int a[2][2] = {0};
    for(int i = 0;i < (int)s.size();i ++){
        if(s[i] == '1')a[i & 1][1]++;
        else a[i & 1][0]++;
    }
    for(int i = 0;i < (int)s.size();i ++){
        if(a[i & 1][0]){
            cout<<0;
            a[i&1][0]--;
        }
        else{
            cout<<1;
        }
    }
    cout<<endl;
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