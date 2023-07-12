#include <iostream>
using namespace std;
#define endl '\n'

const int N = 1e5+50;
int n,m;
int sum[N],a[N],tr[N];


int lowbit(int x){
    return x & -x;
}

void init(){
    for(int i = 1;i <= n;i ++){
        tr[i] = sum[i] - sum[i - lowbit(i)];
    }
}

void add(int x,int y){
    for(;x <= N;x += lowbit(x)){
        tr[x] += y;
    }
}

int query(int x){
    int ans = 0;
    for(;x;x -= lowbit(x))
    {
        ans += tr[x];
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    init();
    while(m--){
        int k,x,y;
        cin>>k>>x>>y;
        if(k == 0){
            cout<<query(y) - query(x - 1)<<endl;
        }
        else if(k == 1){
            add(x,y);
        }
    }
    return 0;
}