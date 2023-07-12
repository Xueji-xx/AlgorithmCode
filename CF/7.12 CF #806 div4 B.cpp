#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool a[50] = {0};
    int sum = 0;
    for(int i = 0;i < s.length();i++){
        if(!a[s[i] - 'A']){
            sum += 2;
            a[s[i] - 'A'] = true;
        }
        else{
            sum += 1;
        }
    }
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}