#include<iostream>
using namespace std;
const int N = 2e7+50;

int p[N];
int v[N],w[N];
int f[N];
int find(int x){
    if(x != p[x])p[x] = find(p[x]);
    return p[x];
}

int main(){
    int n,m,vol;
    cin>>n>>m>>vol;
    for(int i = 0;i < n;i ++){
        p[i] = i;
        cin>> v[i] >> w[i];
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        int pa = find(a),pb = find(b);
        if(find(a) != find(b)){
            p[pa] = p[pb];
            w[pb] += w[pa];
            v[pb] += v[pa];
        }
    }
    for(int i = 0;i < n;i ++){
        if(p[i] == i){
            for(int j = vol;j >= v[i];j --){
                f[j] = max(f[j],f[j-v[i]] + w[i]);
            }
        }
    }
    cout<<f[vol]<<endl;
    return 0;
}