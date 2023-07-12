#include<iostream>
using namespace std;
const int N = 1e6+50;
int a[N];
int tree[N];
int n,m;

int lowbit(int x){
    return x&(-x);
}

void add(int x,int k){
    for(;x <= n;x += lowbit(x)){
        tree[x] += k;
    }
}

int sum(int x){
    int ans = a[x];
    for(;x;x -= lowbit(x)){
        ans += tree[x];
    }
    return ans;
}



int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    while(m--){
        char c;
        cin>>c;
        if(c == 'C'){
            int x,y,z;
            cin>>x>>y>>z;
            add(x,z);
            add(y+1,-z);
        }
        else if(c == 'Q'){
            int x;
            cin>>x;
            cout<<sum(x)<<endl;
        }
    }
    return 0;
}