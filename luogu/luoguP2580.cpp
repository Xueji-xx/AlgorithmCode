#include<iostream>
#include<map>
using namespace std;
const int N = 1e6+12;
int trie[N][26];
int cnt[N];
int id;
map<string,int> vis;


void insert(string s){
    int p = 0;
    for(int i = 0;i < s.size();i ++){
        int x = s[i] - 'a';
        if(trie[p][x] == 0)trie[p][x] = ++id;
        p = trie[p][x];
    }
    cnt[p]++;
}

int find(string s){
    int p = 0;
    for(int i = 0;i < s.size();i ++){
        int x = s[i] - 'a';
        if(trie[p][x] == 0)return 0;
        p = trie[p][x];
    }
    return cnt[p];
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i ++){
        string s;
        cin>>s;
        insert(s);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        int x= find(s);
        if(x == 0)cout<<"WRONG"<<endl;
        else{
            if(vis[s] == 0)cout<<"OK"<<endl,vis[s]++;
            else cout<<"REPEAT"<<endl;
        }
    }
    return 0;
}