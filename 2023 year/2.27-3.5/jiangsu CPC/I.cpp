#include <iostream>
#include <set>
using namespace std;



int main(){
    string s;
    cin>>s;
    set<char> se;
    for(int i = 0;i < s.length();i ++){
        se.insert(s[i]);
    }
    if(se.size() == 1){
        cout<<s.size() - 1<<endl;
    }
    else cout<<0<<endl;
    return 0;
}