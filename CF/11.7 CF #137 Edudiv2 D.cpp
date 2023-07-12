#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = '*' + s;
    int pos1 = -1,pos2 = -1;
    int idx = -1;
    for(int i = 1;i <= s.length();i ++){
        if(s[i] == '1'){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout<<0<<endl;
    }
    else{
        for(int i = idx;i <= s.length();i ++){
            if(s[i] == '0' && pos1 == -1){
                pos1 = pos2 = i;
            }
            else pos2 = i;
        }
        int len = pos2 - pos1 + 1;
        string maxm = "";
        for(int i = idx;i < pos1;i ++){
            string a = s.substr(i,len-1);
            string b = s.substr(idx,pos1-idx);
            for(int j = 0;j < a.length();j ++){
                if(a[j] == '0' && s[pos1 + j] == '0')b += '0';
                else b += '1';
            }
            cout<<b<<endl;
            maxm = max(maxm,b);
        }
        cout<<maxm<<endl;
    }
    return 0;
}
