#include <iostream>
#include <set>
using namespace std;

set<string> st;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        bool f = false;
        cin>>n;
        while(n--){
            string s;
            cin>>s;
            if(s.find("bie") != -1 && st.find(s) == st.end()){
                cout<<s<<endl;
                st.insert(s);
                f = true;
            }
        }
        if(!f)cout<<"Time to play Genshin Impact, Teacher Rice!"<<endl;
    }
    
    return 0;
}