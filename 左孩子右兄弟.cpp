#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+10;
int e[N],ne[N],h[N],idx;
int n;
void add(int a,int b)//�ڽӱ�ӱ� 
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u)
{
    int hmax=0,cnt=0;//hmaxΪu���ӽڵ����߸߶ȣ�cntΪ�ӽڵ�ĸ��� 
    for(int i=h[u];~i;i=ne[i])//����u��ÿ���ӽڵ� 
    {
        int j=e[i]; 
        hmax=max(hmax,dfs(j));//�ݹ��С�ƴ󣬸���hmax 
        cnt++;//�ӽڵ������1 
    }
    return hmax+cnt;//״̬ת�Ʒ��� 
}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);//��ʼ��ʹ��ÿ��ͷָ��ָ��-1 
    for(int i =2;i<=n;i++)
    {
        int x;cin>>x;
        add(x,i);//����xָ��i�ı� 
    }
    cout<<dfs(1);
}

