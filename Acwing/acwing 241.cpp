#include<iostream>
using namespace std;
const int N = 200010;
int tr[4*N];
int a[N];
int lo[N];
int ro[N];
int n;


int lowbit(int x){
    return x & -x;
}

void add(int x,int k){
    while(x <= n){
        tree[x] += k;
        x += lowbit(x);
    }
}

int sum(int x){
    int ans = 0;
    while(x != 0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}


int main(){
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++){
        lo[i] = sum(a[i] - 1);
        ro[i] = sum(n) - sum(a[i]);
        add(a[i],1);
    }
    memset(tr,0,sizeof tr);
    int ans = 0;
    int res = 0;
    for(int i = n;i >= 1;i --){
        int x = sum(n) - sum(a[i]);
        int y = sum(a[i] - 1);
        ans += x*ro[i];
        res += y*lo[i];
        add(a[i],1);
    }
    cout<<ans<<' '<<res<<endl;
    system("pause");
    return 0;
}