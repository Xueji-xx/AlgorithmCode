#include <iostream>
#include <unordered_set>
using namespace std;
int n;
string s;
bool check(int mid){
    unordered_set<string> h;
    for(int i = 0;i + mid - 1 < s.size();i ++){
        auto str = s.substr(i,mid);
        if(h.count(str))return false;
        h.insert(str);
    } 
    return true;
}

int main(){
    cin>>n;
    cin>>s;
    int l = 1,r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    cout<<l<<endl;
    return 0;
}