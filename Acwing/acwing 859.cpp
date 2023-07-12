#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int N = 1e5+50;
int p[N];

struct Edge{
    int a,b,w;
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edge[N];

int find(int x){
    if(p[x] != x)p[x] = find(p[x]);
    return x;
}

int Kruskal(){
    int res = 0,cnt = 0;
    for(int i = 0;i < m;i ++){
        int a = edge[i].a,b = edge[b].b,w = edge[i].w;
        if(find(a) != find(b)){
            p[find(a)] = p[find(b)];
            cnt ++;
            res += w;
        }
    }
    if(cnt == n+1)return res;
    else return 0x3f3f3f3f;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i < m;i ++){
        int a,b,v;
        cin>>a>>b>>v;
        edge[i] = {a,b,v};
    }
    sort(edge,edge + m);
    int t = Kruskal();
    if(t == 0x3f3f3f3f)cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}