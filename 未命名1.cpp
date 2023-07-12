#include <bits/stdc++.h>
using namespace std;
vector <string> vec;
bool vis(string c)
{
    for(int i=0;i<vec.size();i++)
        if(c==vec[i]) return true;
    return false;
}
void dfs()
{
    string c;
    for(int i=0;i<vec.size();i++){
        c=vec[i];
        int l=c.size();
        for(int j=0;j<l/2;j++)
            swap(c[j],c[j+(l+1)/2]);
        if(!vis(c)) vec.push_back(c);
        c=vec[i];
        for(int j=1;j<l;j+=2)
            swap(c[j-1],c[j]);
        if(!vis(c)) vec.push_back(c);
    }
}
int main()
{
    string b;
    int x=0; //0,1,2,3
    for(int n=1;n<=100;n++)
    {
        if(n%4!=x) continue;
        puts("");
        vec.clear();
        b="";
        for(int j=1;j<=n;j++)
            b+='0'+j;
        //cout<<b<<endl;
        vec.push_back(b);
        dfs();
        printf("%d:%d\n",n,vec.size());
    }
    return 0;
}
