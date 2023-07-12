#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
const int N = 4e6+50;
int p[N];
typedef pair<int,int> PII;
int cnt;
vector<PII>e,ue;
unordered_map<int,int> H;

int f(int x){
    if(H.count(x)){
        return H[x];
    }
    return H[x] = cnt++;
}


int find(int x){
    if(x != p[x])p[x] = find(p[x]);
    return p[x];
}

void solve(){
    cnt = 0;
    e.clear(),ue.clear();
    H.clear();
    int n;
    cin>>n;
    for(int i = 0;i < n;i ++){
        int a,b,c;
        cin>>a>>b>>c;
        a = f(a),b = f(b);
        if(c){
            e.push_back({a,b});
        }
        else{
            ue.push_back({a,b});
        }
    }
    for(int i = 0;i < cnt;i ++)p[i] = i;
    for(auto i : e){
        p[find(i.first)] = find(i.second);
    }
    bool flag = true;
    for(auto i:ue){
        if(find(i.first) == find(i.second)){
            flag = false;
            break;
        }
    }
    cout<<(flag?"YES":"NO")<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}