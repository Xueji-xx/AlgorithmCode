#include<iostream>
#include<string.h>
#include<unordered_map>         
#include<queue>
using namespace std;
const int N = 1e5+50;
typedef unsigned long long ULL;
int h[N],p[N];
const int P = 131;
char s[N];
/*string s;*/
        
int main(){
    p[0] = 1;
    for(int i = 1;i < N;i ++)p[i] = p[i-1] * P;
    int m,l;
    while(~scanf("%d %d",&m,&l)){
        scanf("%s",s+1);
        int n = strlen(s+1);
        /*cin>>s;
        s = '1' + s;
        int n = s.length();*/
        for(int i = 1;i <= n;i ++)h[i] = h[i-1] * P + s[i];
        int ans = 0;
        for(int st = 1;st <= l;st ++){
            queue<int> q;
            unordered_map<ULL,int> f;
            for(int i = st;i + l - 1 <= n;i += l){
                ULL val = h[i+l-1] - h[i-1] * p[l];
                q.push(i);
                if(q.size() > m){
                    int t = q.front();
                    q.pop();
                    ULL x = h[t+l-1] - h[t-1] * p[l];
                    f[x] --;
                    if(f[x] == 0)f.erase(x);
                }
                f[val]++;
                if(q.size() == m && f.size() == m)ans ++;
            }
        }
        cout<<ans<<endl;
    }
    system("pause");        
    return 0;
}