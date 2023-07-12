#include <iostream>
using namespace std;

const int N = 1e5+50;
int tr[N][26];
int f1[N],f2[N],cnt;


void insert(string s){
    int rt = 0;
    for(int i = 0;i < s.length();i ++){
        int id = s[i] - 'a';
        if(!tr[rt][id])tr[rt][id] = ++cnt;
        rt = tr[rt][id];
    }
}

void dfs1(int rt){
    f1[rt] = 1;
    for(int i = 0;i < 26;i ++){
        if(tr[rt][i]){
            dfs1(tr[rt][i]);
            if(f1[tr[rt][i]]){
                f1[rt] = 0;
                return;
            }
        }
    }
}

void dfs2(int rt){
    bool flag = true;
    for(int i = 0;i < 26;i ++){
        if(tr[rt][i]){
            dfs2(tr[rt][i]);
            flag = false;
            if(f2[tr[rt][i]]){
                f2[rt] = 0;
                return;
            }
        }
    }
    if(flag)f2[rt] = 0;
    else f2[rt] = 1;
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        string s;
        cin >> s;
        insert(s);
    }
    dfs1(0);//判断先手是否必赢
    dfs2(0);//判断先手是不是必输
    if(!f1[0]){
        if(!f2[0]){
            cout << "First" << endl;
        }
        else{
            if(k % 2)cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }
    else cout << "Second" << endl;
    return 0;
}