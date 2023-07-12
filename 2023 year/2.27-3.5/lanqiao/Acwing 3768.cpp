#include <iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 0;i < s.length();i ++){
        int l,r;
        if(s[i] == 'x'){
            l = i;
            r = i;
            while(s[r]=='x')r++;
            i = r-1;
            if(r - l >= 2)ans += (r - l - 2);
        }
    }
    cout<<ans<<endl;
    return 0;
}