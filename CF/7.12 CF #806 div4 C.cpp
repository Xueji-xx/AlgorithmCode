#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n+5];
    for(int i = 0;i < n;i ++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i ++){
        int cnt;string s;
        cin>>cnt;
        cin>>s;
        for(int j = 0;j < cnt;j ++){
            if(s[j] == 'D'){
                a[i] += 1;
                a[i] %= 10;
            }
            else if(s[j] == 'U'){
                a[i] -= 1;
                if(a[i] < 0)a[i] += 10;
            }
        }
    }
    for(int i = 0;i < n;i ++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

int main(){
        int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}