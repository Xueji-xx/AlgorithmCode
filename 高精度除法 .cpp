#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

vector<int> div(vector<int> &c,int b,int &r){
    vector<int> C;
    for(int i = 0;i < c.size();i ++){
        r = r * 10 + c[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(),C.end());
    while(C.size() > 1 && !C.back())C.pop_back();
    return C;
}


int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int> c;
    for(int i = 0;i < a.length();i ++){
        c.push_back(a[i] - '0');
    }
    int r = 0;
    auto C = div(c,b,r);
    for(int i = C.size()-1;i >= 0;i --)cout<<C[i];
    cout<<endl<<r<<endl;
    return 0;
}