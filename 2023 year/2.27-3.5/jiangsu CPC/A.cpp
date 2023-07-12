#include <iostream>
#include <map>
using namespace std;

string sa[1050],sb[1050];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        cin>>sa[i]>>sb[i];
    }
    for(int i = 1;i <= n;i ++){
        map<string,int> mp;
        int cnt = 0;
        for(int j = i;j <= n;j ++){
            if(sa[j] == sa[i]){
                if(!mp[sb[j]]){
                    cnt++;
                    mp[sb[j]] = 1;
                }
                else break;
                if(cnt == 5){
                    cout<<"PENTA KILL!"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"SAD:("<<endl;
    return 0;
}