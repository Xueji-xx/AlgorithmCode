#include<iostream>
using namespace std;
#define int long long
const int N = 5e6+50;
int n,m;
int tree[N];
int a[N];

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
    while(x){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}



signed main(){
    cin>>n>>m;
    int l = 0,r;
    for(int i = 1;i <= n;i ++){
        cin>>r;
        add(i,r-l);
        l = r;
    }
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int x,y,k;
            cin>>x>>y>>k;
            add(x,k);
            add(y+1,-k);
        }
        else if(op == 2){
            int x;
            cin>>x;
            cout<<sum(x)<<endl;
        }
    }
    system("pause");
    return 0;
}