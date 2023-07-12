#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
#define int long long
unordered_map<string,int> mp;


void bfs(){
    string x = "0000";
    queue<string> q;
    q.push(x);
    mp[x] = 0;
    while(q.size()){
        string t = q.front();
        q.pop();
        for(int k = 1;k <= 4;k ++){ 
            for(int i = 0;i + k - 1 < 4;i ++){  
                int j = i + k - 1;
                string a = t,b = t;
                for(int w = i;w <= j;w ++){
                    a[w] = ((a[w] - '0' + 1) % 10) + '0';
                    b[w] = ((b[w] - '0' + 9) % 10) + '0';
                }
                if(mp.find(a) == mp.end()){
                    q.push(a);
                    mp[a] = mp[t] + 1;
                }
                if(mp.find(b) == mp.end()){
                    q.push(b);
                    mp[b] = mp[t] + 1;
                }
            }
        }
    }
}



signed main(){
    int t;
    cin>>t;
    bfs();
    while(t--){
        string a,b,c = "0000";
        cin>>a>>b;
        for(int i = 0;i < 4;i ++){
            c[i] = (a[i] - b[i] + 10) % 10 + '0';
        }
        cout<<mp[c]<<endl;
    }
    return 0;
}