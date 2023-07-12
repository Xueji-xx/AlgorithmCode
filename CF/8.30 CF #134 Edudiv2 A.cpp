#include<iostream>
#include<set>
using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;
    a += b;
    set<char> s;
    for(int i = 0;i < a.size();i ++){
        s.insert(a[i]);
    }
    cout<<s.size() - 1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}