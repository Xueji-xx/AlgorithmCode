#include <iostream>
#include <string.h>
using namespace std;
#define endl '\n'
const int N = 1e5+50;
int a[N];
int s[N];
int f[N][20];
int n,q;

int query(int l,int r){
    int k = 0;
    while((1 << k) <= r - l + 1)k ++;
    k --;
    int ans = max(f[l][k],f[r - (1 << k) + 1][k]);
    return ans;
}

void init(){
    memset(f,0,sizeof f);
    for(int i = 0;i < n;i ++)f[i][0] = s[i]; 
    for(int j = 1;(1 << j) <= n;j ++){
        for(int i = 0;i + (1 << j) <= n;i ++){
            f[i][j] = max(f[i][j-1],f[i+(1 << (j - 1))][j-1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(~scanf("%d",&n) && n){
        cin >> q;
        for(int i = 0;i < n;i ++)cin >> a[i];
        int cnt = 1;
        s[0] = 1;
        for(int i = 1;i < n;i ++){
            if(a[i] == a[i-1])cnt ++;
            else cnt = 1;
            s[i] = cnt;
        }
        init();
        while(q --){
            int l,r;
            cin >> l >> r;      
            r --;
            l --;
            int cnt = l;
            while(cnt + 1 <= r && a[cnt] == a[cnt + 1])cnt ++;
            int ans = max(query(cnt+1,r),cnt - l + 1);
            cout << ans << endl;
        }
    }
    return 0;
}