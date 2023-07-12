#include <iostream>
#include <map>
using namespace std;
map<int,int> mp;


int main(){
    mp.clear();
    int n,x;
    cin>>n>>x;
    for(int i = 0;i < n;i ++){
        int x;
        cin>>x;
        mp[x]++;
    }
    bool flag = true;
    for(int i = 1;i < x;i ++){
        if(mp[i] % (i + 1) != 0){
            flag = false;
            break;
        }
        mp[i+1] += mp[i]/(i+1);
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}