#include<iostream>
using namespace std;
const int N = 1e6+50;
int son[N][26],cnt[N],idx;




void insert(string s){
    int p = 0;
    for(int i = 0;s[i];i ++){
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string s){
    int p = 0;
    for(int i = 0;s[i];i ++){
        int u = s[i] - 'a';
        if(!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n --){
        char c;
        string s;
        cin>>c;
        cin>>s;
        if(c == 'I')insert(s);
        else if(c == 'Q')cout<<query(s)<<endl;
    }
    system("pause");
    return 0;
}