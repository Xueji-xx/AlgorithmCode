#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+10;
int e[N],ne[N],h[N],idx;
int n;
void add(int a,int b)//邻接表加边 
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u)
{
    int hmax=0,cnt=0;//hmax为u的子节点的最高高度，cnt为子节点的个数 
    for(int i=h[u];~i;i=ne[i])//遍历u的每个子节点 
    {
        int j=e[i]; 
        hmax=max(hmax,dfs(j));//递归从小推大，更新hmax 
        cnt++;//子节点个数加1 
    }
    return hmax+cnt;//状态转移方程 
}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);//初始化使得每个头指针指向-1 
    for(int i =2;i<=n;i++)
    {
        int x;cin>>x;
        add(x,i);//建立x指向i的边 
    }
    cout<<dfs(1);
}

