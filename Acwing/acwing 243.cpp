#include<iostream>
using namespace std;
#define int long long
int n,m;
const int N = 1e5+50;
int a[N],tr[N],tri[N];

int lowbit(int x){
    return x & (-x);
}

void add(int t[],int x,int k){
    for(int i = x;i <= n;i += lowbit(i)){
        t[i] += k;
    }
}

int sum(int t[],int x){
    int ans = 0;
    for(int i = x;i;i -= lowbit(i)){
        ans += t[i];
    }
    return ans;
}

int getsum(int x){
    return sum(tr,x) * (x + 1) - sum(tri,x);
}


signed main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++){
        tr[i] = a[i] - a[i-1];
        tri[i] = tr[i] * i;
    }
    for(int x = 1;x <= n;x ++){
        for (int i = x - 1; i >= x - lowbit(x) + 1; i -= lowbit(i)){
            tr[x] += tr[i], tri[x] += tri[i];
        }
    }
    while(m--){
        char c;
        cin>>c;
        if(c == 'Q'){
            int l,r;
            cin>>l>>r;
            cout<<getsum(r) - getsum(l-1)<<endl;
        }
        else if(c == 'C'){
            int l,r,d;
            cin>>l>>r>>d;
            add(tr,l,d);add(tr,r+1,-d);
            add(tri,l,l*d);add(tri,r+1,(r+1)*-d);
        }
    }
    return 0;
}