#include <iostream>
#include <string.h>
#include <deque>
using namespace std;
const int N = 4e5+50;
int h[N],e[N],w[N],ne[N],dis[N];
bool vis[N];
int cnt;

void add(int a,int b,int c){
    e[cnt] = b;
    w[cnt] = c;
    ne[cnt] = h[a];
    h[a] = cnt++;
}

void spfa(int s){
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    deque<int> q;
    dis[s] = 0;
    vis[s] = true;
    q.push_back(s);
    while(q.size()){
        int t = q.front();
        vis[t] = false;
        q.pop_front();
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                if(!vis[j]){
                    vis[j] = true;
                    if(q.size() && dis[j] < dis[q.front()]){
                        q.push_front(j);
                    }
                    else q.push_back(j);
                }
            }
        }
    }
}


int main(){
    int t,r,p,s;
    cin>>t>>r>>p>>s;
    memset(h,-1,sizeof h);
    for(int i = 1;i <= r;i ++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    for(int i = 1;i <= p;i ++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    spfa(s);
    for(int i = 1;i <= t;i ++){
        if(dis[i] == 0x3f3f3f3f){
            cout<<"NO PATH"<<endl;
        }
        else cout<<dis[i]<<endl;
    }
    return 0;
}