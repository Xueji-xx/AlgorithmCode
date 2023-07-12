#include<iostream>
using namespace std;



int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 0;i < s.length();i ++){
        if(s[i] == 'e' && s[i+1] == 'd' && s[i+2] == 'g' && s[i+3] == 'n' && s[i+4] == 'b')ans++,i += 4;
    }
    cout<<ans<<endl;
    return 0;
}