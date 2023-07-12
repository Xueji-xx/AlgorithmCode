#include<iostream>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s[0] == 'Y' || s[0] == 'y'){
            if(s[1] == 'e' || s[1] == 'E'){
                if(s[2] == 's' || s[2] == 'S'){
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    system("pause");
    return 0;
}