#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<int> a[3][3];
const string S = "win";

int get(vector<int> &x){
    int y = x.back();
    x.pop_back();
    return y;
}

void solve(){
    int n;
    cin>>n;
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < 3;j ++){
            a[i][j].clear();
        }
    }
    string s;
    for(int i = 1;i <= n;i ++){
        cin>>s;
        vector<int> cnt(3);
        for(int j = 0;j < 3;j ++){
            cnt[S.find(s[j])]++;
        }
        for(int x = 0;x < 3;x ++){
            for(int y = 0;y < 3;y ++){
                if(x == y)continue;
                if(cnt[x] > 1 && cnt[y] < 1){
                    a[x][y].push_back(i);
                    cnt[x]--;
                    cnt[y]++;
                }
            }
        }
    }   
    vector<array<int,4>>ans;
    for(int x = 0;x < 3;x ++){
        for(int y = x+1;y < 3;y ++){
            vector<int> &fi = a[x][y];
            vector<int> &se = a[y][x];
            while(!fi.empty() && !se.empty()){
                int f = get(fi);
                int s = get(se);
                ans.push_back({f,x,s,y});
            }
        }
    }
    vector<int> &fi = a[1][0];
    vector<int> &se = a[0][2];
    vector<int> &th = a[2][1];
    while(!fi.empty() && !se.empty() && !th.empty()){
        int f = get(fi);
        int s = get(se);
        int t = get(th);
        ans.push_back({f,1,s,0});
        ans.push_back({s,1,t,2});
    }
    vector<int> &f1 = a[0][1];
    vector<int> &s2 = a[1][2];
    vector<int> &t3 = a[2][0];
    while(!f1.empty() && !s2.empty() && !t3.empty()){
        int f = get(f1);
        int s = get(s2);
        int t = get(t3);
        ans.push_back({f,0,s,1});
        ans.push_back({s,0,t,2});
    }
    cout<<ans.size()<<endl;
    for(auto [i,x,j,y] : ans){
        cout<<i<<' '<<S[x]<<' '<<j<<' '<<S[y]<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}