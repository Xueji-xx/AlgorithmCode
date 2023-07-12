#include<iostream>
#include<algorithm>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    string a,b;
    cin>>a>>b;
    sort(b.begin(),b.end(),greater<char>());
    sort(a.begin(),a.end(),greater<char>());
    string c = "\0";
    int cnta,cntb;
    cnta = cntb = 0;
    while(!a.empty() && !b.empty()){
        if(a.back() < b.back()){
            if(cnta != k)cnta++,cntb = 0,c+=a.back(),a.pop_back();
            else cntb++,cnta = 0,c+= b.back(),b.pop_back();
        } 
        else{
            if(cntb != k)cntb++,cnta = 0,c+= b.back(),b.pop_back();
            else cnta++,cntb = 0,c+=a.back(),a.pop_back();
        }
    }
    cout<<c<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}