#include <iostream>
using namespace std;
const int N = 50010;

bool vis[N];
int pri[N];
int cnt;
int mob[N],s[N];

void init(int n){
    mob[1] = 1;
    for(int i = 2;i <= n;i ++){
        if(!vis[i]){
            pri[cnt++] = i;
            mob[i] = -1;
        }
        for(int j = 0;pri[j] * i <= n;j ++){
            int t = pri[j] * i;
            vis[t] = true;
            if(i % pri[j] == 0){
                mob[t] = 0;
                break;
            }
            mob[t] = mob[i] * -1;
        }
    }
    for(int i = 1;i <= n;i ++){
        s[i] = s[i-1] + mob[i];
    }
}

int main(){
    init(N);
    int t;
    cin>>t;
    while(t--){
        int a,b,d;
        cin>>a>>b>>d;
        a /= d;b /= d;
        int n = min(a,b);
        int res = 0;
        for(int l = 1,r;l <= n;l = r + 1){
            r = min(n,min(a/(a/l),b/(b/l)));
            res += (s[r] - s[l-1]) * (a/l)*(b/l);
        }
        cout<<res<<endl;
    }
    return 0;
}