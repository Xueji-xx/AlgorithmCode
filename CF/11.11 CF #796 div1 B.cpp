#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define endl '\n'
const int N = 205, M = 505, INF = 0x3f3f3f3f;
char s[M];
int w[M],id[M];

int ask(int x){
    if(x)s[x] ^= 1;
    cout<<"? "<<s+1<<endl;
    if(x)s[x]^= 1;
    int t;
    cin>>t;
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i ++)s[i] = '0';
    for(int i = 1;i <= m;i ++)w[i] = ask(i);    
    for(int i = 1;i <= m;i ++)id[i] = i;
    sort(id+1,id+1+m,[&](int x,int y){
        return w[x] < w[y];
    });
    int res = w[id[1]];
    s[id[1]] = '1';
    for(int i = 2;i <= m;i ++){
        int t = ask(id[i]);
        if(t == res + w[id[i]]){
            res += w[id[i]];
            s[id[i]] = '1';
        }
    }
    cout<<"! "<<res<<endl;
    return 0;
}