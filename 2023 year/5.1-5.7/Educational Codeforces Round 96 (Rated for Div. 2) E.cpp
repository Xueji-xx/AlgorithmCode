#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define int long long

const int N = 4e5+50;
int a[N];
queue<int> g[200];
int tr[N];
int n;
char s[N],t[N];

int lowbit(int x){
    return x & (-x);
}

void add(int x,int d){
    while(x <= n){
        tr[x] += d;
        x += lowbit(x);
    }
}

int query(int x){
    int sum = 0;
    while(x){
        sum += tr[x];
        x -= lowbit(x);
    }
    return sum;
}


signed main(){
    cin >> n;
    scanf("%s",s+1);
    for(int i = 1;i <= n;i ++){
        g[s[i] - '0'].push(i);
    }
    for(int i = 1;i <= n;i ++){
        t[i] = s[n - i + 1];
    }
    
    for(int i = 1;i <= n;i ++){
        a[i] = g[t[i] - '0'].front();
        g[t[i] - '0'].pop();
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        add(a[i],1);
        ans += (i - query(a[i]));
    }
    cout << ans << endl;
    return 0;
}