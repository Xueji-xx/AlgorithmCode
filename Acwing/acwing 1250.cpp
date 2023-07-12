#include<iostream>
using namespace std;
const int N = 400010;
int p[N];

inline int get(int x,int y){
    return x*n+y;
}

int find(int x){
    if(p[x] != x)p[x] = find(x);
    return p[x];
}



int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n*m;i ++)p[i] = i;
    int ans = 0;
    for(int i = 1;i <= m;i ++){
        int x,y;
        char c;
        cin>>x>>y>>c;
        x--,y--;
        int a = get(x,y),b;
        if(c == 'D')b = get(x+1,y);
        else if(c == 'R')b = get(x,y+1);
        int pa = find(a),pb = find(b);
        if(pa == pb){
            ans = i;
            break;
        }
        p[pa] = pb;
    }
    if(ans)cout<<ans<<endl;
    else cout<<"draw"<<endl;
    return 0;
}