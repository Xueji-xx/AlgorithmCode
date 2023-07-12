#include <iostream>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        string s = "314159265358979323846264338327950288419716939937510";
        string t;
        cin>>t;
        int cnt = 0;
        for(int i = 0;i < t.length();i ++){
            if(t[i] != s[i]){
                break;
            }
            else cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}