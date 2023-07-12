#include<iostream>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        for(int i = 0;i < s.length();i += m){
            string a = s.substr(i,m);
            cout<<a<<endl;
        }
    }
    system("pause");
    return 0;
}