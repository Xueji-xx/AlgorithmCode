#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define int long long
const int N = 5e4+500;
int a[N],b[50],c[50],d[50],sum,per;
int n,k;

bool check(int mid){
    for(int i = 0;i <= 31;i ++)c[i] = 0;
    for(int i = 0;i <= 31;i ++)d[i] = b[i];
    priority_queue<int> q;
    for(int i = 1;i <= n;i ++){
        int x = mid * a[i];
        q.push(x);
    }
    for(int i = 19;~i;i --){
        if(q.size() && q.top() <= (1 << i) && d[i]){
            q.pop();
            d[i] --;
        }
        while(q.size() && q.top() >= (1 << i) && d[i]){
            int t = q.top();
            int tt = t / (1 << i);
            int ttt = min(tt,d[i]);
            tt -= ttt,d[i] -= ttt;
            q.pop();
            int x = t - ttt * (1 << i);
            if(x == 0)continue;
            q.push(x);
        }
        while(q.size() && q.top() <= (1 << i) && d[i]){
            q.pop();
            d[i] --;
        }
    }
    int j = 19;
    while(q.size()){
        if(j <= 0)break;
        while(j >= 0 && !d[j])j --;
        while(q.size() && j >= 0 && q.top() < (1 << j) && d[j]){
            if(j < 0)break;
            q.pop();
            d[j] --;
        }
        j --;
    }
    if(q.size())return false;
    return true;
}


void solve(){
    cin>>n>>k;
    memset(b,0,sizeof b);
    per = sum = 0;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        per += a[i];
    }
    for(int i = 0;i < k;i ++){
        cin>>b[i];
        sum += (1 << i)*b[i];
    }
    int l = 0,r = sum / per;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid))l = mid;
        else r = mid - 1;
    }
    cout << l <<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}