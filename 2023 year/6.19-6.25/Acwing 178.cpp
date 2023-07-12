#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int n,m,s,t,k;
const int N = 1050;
const int M = 200010;
int h[N],fh[N],e[M],w[M],ne[M],idx;
int dis[N],cnt[N];
bool st[N];
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

void add(int h[],int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    dis[t] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, t});
    while (heap.size())
    {
        auto tt = heap.top();
        heap.pop();
        int ver = tt.second, distance = tt.first;
        if (st[ver])
        {
            continue;
        }
        st[ver] = true;
        for (int i = fh[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[ver] + w[i])
            {
                dis[j] = dis[ver] + w[i];
                heap.push({dis[j], j});
            }
        }
    }
}


int astar()
{
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dis[s], {0, s}});
    while (heap.size())
    {
        auto tt = heap.top();
        heap.pop();
        int ver = tt.second.second, distance = tt.second.first;
        cnt[ver] ++ ;
        if (cnt[t] == k)
        {
            return distance;
        }
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (cnt[j] < k)
            {
                heap.push({distance + w[i] + dis[j], {distance + w[i], j}});
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    memset(fh,-1,sizeof fh);
    while(m --){
        int a,b,c;
        cin >> a >> b >> c;
        add(h,a,b,c);
        add(fh,b,a,c);
    }
    cin >> s >> t >> k;
    if(s == t){
        k ++;
    }
    dijkstra();
    cout << astar() << endl;
    return 0;
}