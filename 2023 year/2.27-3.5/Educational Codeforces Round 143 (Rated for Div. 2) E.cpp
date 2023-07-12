#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define int long long

const int N = 3e5+ 50;
int a1[N],a2[N];
int sum1[N],sum2[N];
int ans[N];

struct Node{
    int len,val,ed;
}q[N];

void solve(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        cin>>a1[i];
        a2[i] = a1[i] - i;
        ans[i] = a1[i];
        sum1[i] = sum1[i-1] + a1[i];
        sum2[i] = sum2[i-1] + a2[i];
    }
    int h = 0,t = -1;
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        sum += a2[i];
        Node cur = {1,a2[i],i};
        while(h <= t && q[t].val >= a2[i]){
            sum -= (q[t].val - a2[i]) * q[t].len;
            cur.len += q[t--].len;
        }
        q[++t] = cur;
        while(h <= t){
            if(q[h].val + q[h].ed <= 0){
                h++;
                continue;
            }
            if(q[h].val + q[h].ed - q[h].len + 1 <= 0){
                int len = q[h].val + q[h].ed;
                sum -= (q[h].len - len) * q[h].val;
                q[h].len = len;
            }
            break;
        }
        int pre = q[h].ed - q[h].len;
        ans[i] += sum1[pre] + sum2[i-1] - sum2[pre] - sum + a2[i];
    }
    reverse(a1+1,a1+1+n);
    for(int i = 1;i <= n;i ++)a2[i] = a1[i] - i;
    for(int i = 1;i <= n;i ++){
        sum1[i] = a1[i] + sum1[i-1];
        sum2[i] = a2[i] + sum2[i-1];
    }
    h = 0,t = -1;
    sum = 0;
    for(int i = 1;i <= n;i ++){
        sum += a2[i];
        Node cur = {1,a2[i],i};
        while(h <= t && q[t].val >= a2[i]){
            sum -= (q[t].val - a2[i]) * q[t].len;
            cur.len += q[t--].len;
        }
        q[++t] = cur;
        while(h <= t){
            if(q[h].val + q[h].ed <= 0){
                h++;
                continue;
            }
            if(q[h].val + q[h].ed - q[h].len + 1 <= 0){
                int len = q[h].val + q[h].ed;
                sum -= (q[h].len - len) * q[h].val;
                q[h].len = len;
            }
            break;
        }
        int pre = q[h].ed - q[h].len;
        ans[n - i + 1] += sum1[pre] + sum2[i-1] - sum2[pre] - sum + a2[i];
    }
    cout<<*min_element(ans+1,ans+1+n)<<endl;
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