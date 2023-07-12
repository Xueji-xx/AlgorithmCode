#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0;i < s.length();i ++){
        if(s[i-1] == 'L' || s[i+1] == 'L' || s[i] == 'L');
        else s[i] = 'C';
    }
    cout<<s<<endl;
    return 0;
}